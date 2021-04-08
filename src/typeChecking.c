#include <stdlib.h>
#include <string.h>
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
	if(result->oper=='+' || result->oper=='-' ||  result->oper=='*' || result->oper=='/' || result->oper=='<' || strcmp(result->oper,"<=") ||  result->oper=='=')
		if(result->opr.op[0]->type!=typeInt || result->opr.op[1]->type!=typeInt)
			yyerror("Cannot perform arithmetic operation with one non-integer constant.");
	if(strcmp(result->oper,"NOT"))
		if(result->opr.op[0]->type!=typeBool)
			yyerror("Requires Boolean operand.");
	if(result->oper=='.')
		if(result->opr.op[1]->type!=typeId)
			yyerror("Object identifier must follow the . operator.");
	if(strcmp(result->oper,"<-"))
		if(result->opr.op[0]->type!=typeId)
			yyerror("Assignment not possible to this type.");
	va_end(ap);     
	return result; 
}
