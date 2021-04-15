#include <stdlib.h>
#include <string.h>
#include "typeChecking.h"
#include <stdarg.h>
#include <stdio.h>
#include "y.tab.h"
static int lbl;
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
	result->id.i = id;     
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
	if(result->opr.oper=='+' || result->opr.oper=='-' ||  result->opr.oper=='*' || result->opr.oper=='/' || result->opr.oper=='<' || !strcmp(result->opr.oper,"<=") ||  result->opr.oper=='=')
		if(result->opr.op[0]->type!=typeInt || result->opr.op[1]->type!=typeInt)
			yyerror("Cannot perform arithmetic operation with one non-integer constant.");
	if(!strcmp(result->opr.oper,"NOT"))
		if(result->opr.op[0]->type!=typeBool)
			yyerror("Requires Boolean operand.");
	if(result->opr.oper=='.')
		if(result->opr.op[1]->type!=typeId)
			yyerror("Object identifier must follow the . operator.");
	if(!strcmp(result->opr.oper,"<-"))
		if(result->opr.op[0]->type!=typeId)
			yyerror("Assignment not possible to this type.");
	va_end(ap);     
	return result; 
}

int ex(nodeType *p) 
{     
	int lbl1, lbl2;     
	if (!p) 
		return 0;     
	switch(p->type) 
	{     
		case typeInt:                
			printf("\tpush\t%d\n", p->i.value);          
			break; 
		case typeBool:                
			printf("\tpush\t%d\n", p->b.value);          
			break; 
		case typeStr:                
			printf("\tpush\t%s\n", p->s.value);          
			break;     
		case typeId:                 
			printf("\tpush\t%s\n", p->id.i);          
			break;     
		case typeOpr:         
			switch(p->opr.oper) 
			{         
				case WHILE:             
					printf("L%03d:\n", lbl1 = lbl++);             
					ex(p->opr.op[0]);             
					printf("\tjz\tL%03d\n", lbl2 = lbl++);             
					ex(p->opr.op[1]);             
					printf("\tjmp\tL%03d\n", lbl1);             
					printf("L%03d:\n", lbl2);             
					break;         
				case IF:             
					ex(p->opr.op[0]);             
					if (p->opr.nops > 2) 
					{                 
						/* if else */                 
						printf("\tjz\tL%03d\n", lbl1 = lbl++);                 
						ex(p->opr.op[1]);                 
						printf("\tjmp\tL%03d\n", lbl2 = lbl++);                 
						printf("L%03d:\n", lbl1);                 
						ex(p->opr.op[2]);                 
						printf("L%03d:\n", lbl2);             
					} 
					else 
					{                 
						/* if */                 
						printf("\tjz\tL%03d\n", lbl1 = lbl++);                 
						ex(p->opr.op[1]);                 
						printf("L%03d:\n", lbl1);             
					}             
					break;         
        			case ASSIGN:                    
					ex(p->opr.op[1]);             
					printf("\tpop\t%c\n", p->opr.op[0]->id.i);             
					break;         
				case '~':                 
					ex(p->opr.op[0]);             
					printf("\tneg\n");             
					break; 
				case DARROW:
					ex(p->opr.op[2]);
					printf("\tpop\t%s\n",p->opr.op[0]->id.i);
					break;   
				case '=':
					ex(p->opr.op[0]);                         
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
					ex(p->opr.op[0]);
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
				
				default:             
					ex(p->opr.op[0]);             
					ex(p->opr.op[1]);             
					switch(p->opr.oper) 
					{             
						case '+':   printf("\tadd\n"); break;             
						case '-':   printf("\tsub\n"); break;              
						case '*':   printf("\tmul\n"); break;             
						case '/':   printf("\tdiv\n"); break;             
						case '<':   printf("\tcompLT\n"); break;                         
						case LE:    printf("\tcompLE\n"); break;                         
						case 284:    printf("\tcompEQ\n"); break; //Comparison =             
					}         
				}     
			}     
			return 0; 
}
