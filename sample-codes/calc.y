%{
void yyerror (char *s);
int yylex();
#include<stdio.h> /* C declarations used in actions */
#include<stdlib.h>
#include<ctype.h>
int symbols[52];
int symbolVal(char symbol);
void updateSymbolVal(char symbol, int val);
%}

/* Yacc definitions */
%union {int num; char id;} /*Union specifies the different types that the lexical analyzer can return */ 
%start line /* Indicates which of the following productions in the middle section is going to be the starting production */
%token print /* Expect a token from lex that must have the command to print out the value */
%token exit_command 
%token <num> number
%token <id> identifier
%type <num> line exp term /* Type assigns a type to the non terminal appearing on the right hand side of the grammar */
%type <id> assignment

%%

/* Descriptions of expected inputs corresponding actions in C */

line	: assignment ';'	{;}
     	| exit_command ';'	{exit(EXIT_SUCCESS);}
	| print exp ';'		{printf("Printing %d\n", $2);}
	| line assignment ';'	{;}
	| line print exp ';'	{printf("Printing %d\n", $3);}
	| line exit_command ';'	{exit(EXIT_SUCCESS);}
	;

assignment : identifier '=' exp {updateSymbolVal($1, $3);}
	   ;
exp	: term			{$$ = $1;}
    	| exp '+' term		{$$ = $1 + $3;}
	| exp '-' term		{$$ = $1 - $3;}
	;
term	: number		{$$ = $1;}
     	| identifier		{$$ = symbolVal($1);}
	;

%%
		/* C Code */
int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token))
	{
		idx = token - 'a' + 26;
	}
	else if(isupper(token))
	{
		idx = token - 'A';
	}
	return idx;
}

/* retuens the value of a given symbol*/
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol*/
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main(void)
{
	/*init symbol table*/
	int i;
	for(i=0; i<52; i++)
	{
		symbols[i] = 0;
	}
	return yyparse ( );
}

void yyerror(char* s) {fprintf(stderr, "%s\n", s);}

