#include <stdlib.h>
#include <string.h>
#include "typeChecking.h"
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include "y.tab.h"
#include "cool.h"
static int lbl;
extern TAC *tactable;
static int temporary;
static int nentries=-1;
static nodeType *stack[10];
extern table *t;
char temp[10];
char label[10];
char number[10];
/*Check if dollar stuff gives int or char * */

/*Handling constant datatypes */
/*Boolean*/
nodeType *bool_constant(char *value)
{
	nodeType *result;     
	/* allocate node */     
	if((result = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");     /*Don't know if it will work. Else will comment */
	/* copy information */     
	result->type = typeBool;     
	result->b.value = value;     
	return result;
}

/*Integer*/
nodeType *integer_constant(int value)
{
	nodeType *result;     
	/* allocate node */     
	if((result = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");     /*Don't know if it will work. Else will comment */
	/* copy information */     
	result->type = typeInt;     
	result->i.value = value;     
	return result;
}


/*String*/
nodeType *str_constant(char *value)
{
	nodeType *result;     
	/* allocate node */     
	if((result = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");     /*Don't know if it will work. Else will comment */
	/* copy information */     
	result->type = typeStr;     
	result->s.value = value;     
	return result;
}

/*Handling identifiers */
nodeType *identifier(char *id) 
{     
	nodeType *result;     
	/* allocate node */     
	if ((result = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");     
	/* copy information */    
	result->type = typeId;     
	result->id.i = strdup(id);    
	//printf("Created identifier for %s\n",id); 
	return result; 
}

nodeType *opr(int oper, int nops, ...) 
{     
	va_list ap;     
	nodeType *result;     
	int i;     
	/* allocate node */     
	if ((result = malloc(sizeof(nodeType))) == NULL)         
		yyerror("out of memory");     
	if ((result->opr.op = malloc(nops * sizeof(nodeType))) == NULL)         
		yyerror("out of memory");     
	/* copy information */     
	result->type = typeOpr;     
	result->opr.oper = oper;     
	result->opr.nops = nops;     
	va_start(ap, nops);     
	for (i = 0; i < nops; i++)         
		result->opr.op[i] = va_arg(ap, nodeType *); 
	/*if(result->opr.oper=='+' || result->opr.oper=='-' ||  result->opr.oper=='*' || result->opr.oper=='/' || result->opr.oper=='<'|| result->opr.oper==DARROW)
		if(result->opr.op[0]->type!=typeInt || result->opr.op[1]->type!=typeInt || result->opr.op[0]->type!=typeId || result->opr.op[1]->type!=typeId)
			yyerror("Cannot perform arithmetic operation with one non-integer constant.");
	if(result->opr.oper==NOT)
		if(result->opr.op[0]->type!=typeBool)
			yyerror("Requires Boolean operand.");*/
	if(result->opr.oper=='.')
		if(result->opr.op[1]->type!=typeId)
			yyerror("Object identifier must follow the . operator.");
	va_end(ap);     
	return result; 
}



nodeType *ex(nodeType *p) 
{
	nodeType *arg1,*arg2;
	tac *row;
	int lbl1, lbl2;  
	if (!p) 
		return NULL;     
	switch(p->type) 
	{     
		case typeInt:                
			printf("\tpush\t%d\n", p->i.value);
			stack[++nentries]=p;          
			break; 
		case typeBool:                
			printf("\tpush\t%d\n", p->b.value);
			stack[++nentries]=p;         
			break; 
		case typeStr:                
			printf("\tpush\t%s\n", p->s.value);     
			stack[++nentries]=p;     
			break;     
		case typeId:                 
			printf("\tpush\t%s\n", p->id.i);
			stack[++nentries]=p;          
			break;     
		case typeOpr:         
			switch(p->opr.oper) 
			{         
				case WHILE:             
					printf("L%03d:\n", lbl1 = lbl++);  
					arg1=NULL;
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					strcpy(label,"L");
					snprintf(number,3,"%d",lbl1);
					strcat(label,number);
					row->oprtr=identifier("Label");
					row->arg1=NULL;
					row->arg2=NULL;
					row->temp=identifier(label);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;            
					ex(p->opr.op[0]);             
					printf("\tjz\tL%03d\n", lbl2 = lbl++); 
					arg1=NULL;
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					strcpy(label,"L");
					snprintf(number,3,"%d",lbl2);
					strcat(label,number);
					row->oprtr=identifier("goto");
					row->arg1=NULL;
					row->arg2=NULL;
					row->temp=identifier(label);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;              
					ex(p->opr.op[1]);             
					printf("\tjmp\tL%03d\n", lbl1); 
					arg1=NULL;
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					strcpy(label,"L");
					snprintf(number,3,"%d",lbl1);
					strcat(label,number);
					row->oprtr=identifier("goto");
					row->arg1=NULL;
					row->arg2=NULL;
					row->temp=identifier(label);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;              
					printf("L%03d:\n", lbl2);   
					arg1=NULL;
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					strcpy(label,"L");
					snprintf(number,3,"%d",lbl2);
					strcat(label,number);
					row->oprtr=identifier("Label");
					row->arg1=NULL;
					row->arg2=NULL;
					row->temp=identifier(label);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;            
					break;         
				case IF:             
					ex(p->opr.op[0]); 
					printf("\tjz\tL%03d\n", lbl1 = lbl++);
					arg1=NULL;
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					strcpy(label,"L");
					snprintf(number,3,"%d",lbl1);
					strcat(label,number);
					row->oprtr=identifier("goto");
					row->arg1=NULL;
					row->arg2=NULL;
					row->temp=identifier(label);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;                   
					ex(p->opr.op[1]);            
					if (p->opr.nops > 2) 
					{                 
						/* if else */                                  
						printf("\tjmp\tL%03d\n", lbl2 = lbl++);
						arg1=NULL;
						arg2=NULL; 
						row=(tac *)malloc(sizeof(tac));
						strcpy(label,"L");
						snprintf(number,3,"%d",lbl2);
						strcat(label,number);
						row->oprtr=identifier("goto");
						row->arg1=NULL;
						row->arg2=NULL;
						row->temp=identifier(label);
						//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
						stack[++nentries]=row->temp;            
						if(tactable->nrows==0)
						tactable->tacRow=row;
						else
						{
							tac *cur=tactable->tacRow;
							while(cur->next!=NULL)
								cur=cur->next;
							cur->next=row;
						}
						tactable->nrows++;                   
						printf("L%03d:\n", lbl1);
						arg1=NULL;
						arg2=NULL; 
						row=(tac *)malloc(sizeof(tac));
						strcpy(label,"L");
						snprintf(number,3,"%d",lbl1);
						strcat(label,number);
						row->oprtr=identifier("Label");
						row->arg1=NULL;
						row->arg2=NULL;
						row->temp=identifier(label);
						//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
						stack[++nentries]=row->temp;            
						if(tactable->nrows==0)
							tactable->tacRow=row;
						else
						{
							tac *cur=tactable->tacRow;
							while(cur->next!=NULL)
								cur=cur->next;
							cur->next=row;
						}
						tactable->nrows++;                   
						ex(p->opr.op[2]);                 
						printf("L%03d:\n", lbl2);
						arg1=NULL;
						arg2=NULL; 
						row=(tac *)malloc(sizeof(tac));
						strcpy(label,"L");
						snprintf(number,3,"%d",lbl2);
						strcat(label,number);
						row->oprtr=identifier("Label");
						row->arg1=NULL;
						row->arg2=NULL;
						row->temp=identifier(label);
						//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
						stack[++nentries]=row->temp;            
						if(tactable->nrows==0)
							tactable->tacRow=row;
						else
						{
							tac *cur=tactable->tacRow;
							while(cur->next!=NULL)
								cur=cur->next;
							cur->next=row;
						}
						tactable->nrows++;               
					} 
					else   
					{                                
						printf("L%03d:\n", lbl1);  
						arg1=NULL;
						arg2=NULL; 
						row=(tac *)malloc(sizeof(tac));
						strcpy(label,"L");
						snprintf(number,3,"%d",lbl1);
						strcat(label,number);
						row->oprtr=identifier("Label");
						row->arg1=NULL;
						row->arg2=NULL;
						row->temp=identifier(label);
						//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
						stack[++nentries]=row->temp;            
						if(tactable->nrows==0)
							tactable->tacRow=row;
						else
						{
							tac *cur=tactable->tacRow;
							while(cur->next!=NULL)
								cur=cur->next;
							cur->next=row;
						}
						tactable->nrows++;  
					}                        
					break;         
        			case ASSIGN:                    
					printf("\tpush\t%s\n", p->opr.op[0]->id.i); 
					ex(p->opr.op[1]);
					arg1=stack[nentries--];
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					row->oprtr=p;
					row->arg1=arg1;
					row->arg2=NULL;
					row->temp=p->opr.op[0];
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;        
					printf("\tpop\n");             
					break;         
				case '~':                 
					ex(p->opr.op[0]);             
					printf("\tneg\n"); 
					arg1=stack[nentries--];
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					row->oprtr=p;
					row->arg1=arg1;
					row->arg2=NULL;
					strcpy(temp,"t");
					snprintf(number,3,"%d",temporary++);
					strcat(temp,number);
					row->temp=identifier(temp);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;
					break; 
				case DARROW:
					ex(p->opr.op[2]);
					arg1=stack[nentries--];
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					row->oprtr=p;
					row->arg1=arg1;
					row->arg2=NULL;
					strcpy(temp,"t");
					snprintf(number,3,"%d",temporary++);
					strcat(temp,number);
					row->temp=identifier(temp);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;
					printf("\tpop\t%s\n",p->opr.op[0]->id.i);
					break;   
				case '=':
					ex(p->opr.op[0]); 
					arg1=stack[nentries--];
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					row->oprtr=p;
					row->arg1=arg1;
					row->arg2=NULL;
					strcpy(temp,"t");
					snprintf(number,3,"%d",temporary++);
					strcat(temp,number);
					row->temp=identifier(temp);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;                        
					break;  
				case IN:
					ex(p->opr.op[2]);
					ex(opr(DARROW,3,p->opr.op[0],p->opr.op[1]));
					break;
				case LET:
					ex(p->opr.op[2]);
					ex(p->opr.op[1]);
					ex(p->opr.op[0]);
					break;
				case '@':
					ex(p->opr.op[0]);
					printf("\tpop\t%s\n",p->opr.op[1]->id.i);
					break;
				case '(':
					ex(p->opr.op[2]);
					ex(p->opr.op[0]);
					printf("\tpop\t%s\n",p->opr.op[1]->id.i);
					break;
				case ' ':
					ex(p->opr.op[1]);
					break;
				case ')':
					ex(p->opr.op[0]);
					ex(p->opr.op[1]);
					break;
				case '.':
					ex(p->opr.op[0]);
					ex(p->opr.op[1]);
					break;
				case 'a':
					ex(p->opr.op[2]);
					ex(p->opr.op[0]);
					ex(p->opr.op[1]);
					break;
				case CASE:
					ex(p->opr.op[0]);
					ex(p->opr.op[1]);
					break;
				case NOT:
					ex(p->opr.op[0]);             
					arg1=stack[nentries--];
					arg2=NULL; 
					row=(tac *)malloc(sizeof(tac));
					row->oprtr=p;
					row->arg1=arg1;
					row->arg2=NULL;
					strcpy(temp,"t");
					snprintf(number,3,"%d",temporary++);
					strcat(temp,number);
					row->temp=identifier(temp);
					//printf("%c\t%i\t(null)\t%s\n",row->oprtr->opr.oper,row->arg1->i.value,row->temp->id.i);
					stack[++nentries]=row->temp;            
					if(tactable->nrows==0)
						tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;
					break; 
				default:             
					ex(p->opr.op[0]);             
					ex(p->opr.op[1]);             
					switch(p->opr.oper) 
					{             
						case '+':   
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%s\n",arg1->id.i,arg2->id.i);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%s\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->id.i,row->temp->id.i);
							stack[++nentries]=row->temp;
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++; 
							break;                          
						case '-':   
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%d\n",arg1->id.i,arg2->i.value);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%d\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->i.value,row->temp->id.i);
							stack[++nentries]=row->temp;
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++; 
							break;              
						case '*':
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%d\n",arg1->id.i,arg2->i.value);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%d\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->i.value,row->temp->id.i);
							stack[++nentries]=row->temp; 
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++; 
							break;             
						case '/':   
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%d\n",arg1->id.i,arg2->i.value);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%d\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->i.value,row->temp->id.i);
							stack[++nentries]=row->temp; 
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++; 
							break;             
						case '<':   
							printf("\tcompLT\n");
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%d\n",arg1->id.i,arg2->i.value);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%d\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->i.value,row->temp->id.i);
							stack[++nentries]=row->temp; 
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++;  
							break;                         
						case LE:    
							printf("\tcompLE\n");
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%d\n",arg1->id.i,arg2->i.value);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%d\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->i.value,row->temp->id.i);
							stack[++nentries]=row->temp; 
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++;  
							break;                         
						case 285:    
							printf("\tcompEQ\n"); 
							arg1=stack[nentries--];
							arg2=stack[nentries--]; 
							//printf("Arg1:%s Arg2:%d\n",arg1->id.i,arg2->i.value);
							row=(tac *)malloc(sizeof(tac));
							row->oprtr=p;
							row->arg1=arg1;
							row->arg2=arg2;
							strcpy(temp,"t");
							sprintf(number,"%d",temporary++);
							strcat(temp,number);
							row->temp=identifier(temp);
							//printf("%c\t%s\t%d\t%s\n",row->oprtr->opr.oper,row->arg1->id.i,row->arg2->i.value,row->temp->id.i);
							stack[++nentries]=row->temp; 
							if(tactable->nrows==0)
								tactable->tacRow=row;
							else
							{
								tac *cur=tactable->tacRow;
								while(cur->next!=NULL)
									cur=cur->next;
									cur->next=row;
							}
							tactable->nrows++; 
							break;             //Comparison =             
					}         
				}     
			}     
			return p; 
}

void display_tac_table(TAC *t)
{
	tac *cur=t->tacRow;
	printf("+-------+-------+-------+-------+-----+\n");
	printf("|OPERATOR|ARGUMENT 1|ARGUMENT 2|RESULT|\n");
	while(cur!=NULL)
	{
		if(cur->oprtr->type==typeId)
			printf("%s\t|",cur->oprtr->id.i);
		else
			printf("%d\t |",cur->oprtr->opr.oper);
		if(cur->arg1==NULL)
			printf("(null)\t|");
		else if(cur->arg1->type==typeId)
			printf("%s|",cur->arg1->id.i);
		else
			printf("%d|",cur->arg1->i.value);
		if(cur->arg2==NULL)
			printf("(null)\t|");
		else if(cur->arg2->type==typeId)
			printf("%s\t|",cur->arg2->id.i);
		else
			printf("%d\t|",cur->arg2->i.value);
		printf("%s\t|\n",cur->temp->id.i);
		cur=cur->next;
	}
	printf("+-------+-------+-------+-------+-------+\n");
}
