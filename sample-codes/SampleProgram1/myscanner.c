#include<stdio.h>
#include<stdlib.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
//We are telling the compiler that we need to connect to those things in the other file via this

char *names[] = {NULL, "db_type", "db_name", "db_table_prefix", "db_port"};

int main(void)
{
	int ntoken, vtoken;
	ntoken = yylex();
	while(ntoken)
	{
		printf("%d\n", ntoken);
		if(yylex() != COLON)
		{
			printf("Syntax error in line %d, expected a ':' but found %s\n", yylineno, yytext);
			return 1;
		}
		vtoken = yylex(); //Value token
		switch(ntoken)
		{
			case TYPE:
			case NAME:
			case TABLE_PREFIX:
				if(vtoken != IDENTIFIER)
				{
					printf("Syntax error in line %d, expected a ':' but found %s\n", yylineno, yytext);
					return 1;
				}
				printf("%s is set to %s\n", names[ntoken], yytext);
				break;
			case PORT:
				if(vtoken != INTEGER)
				{
					printf("Syntax error in line %d, expected a ':' but found %s\n", yylineno, yytext);
					return 1;
				}
				printf("%s is set to %s\n", names[ntoken], yytext);
				break;
			default:
				printf("Syntax Error in line %d\n", yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}

