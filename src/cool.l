%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>
#include "cool.h"
#include "typeChecking.h"

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   

extern table *t;
entry* node = NULL;
int yylex();
void yyerror(char* s);
char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;
#include "y.tab.h"
int mcomment_count; /* to handle nested multiline comments */
%}

INTEGER			[0-9]+
TYPE_ID			[A-Z][a-zA-Z0-9_]*
OBJ_ID			[a-z][a-zA-Z0-9_]*
COMMENT_S		"--".*	
COMMENT_M		(\*).*(\*)
CLASS			[Cc][Ll][Aa][Ss][Ss]
ELSE			[Ee][Ll][Ss][Ee]
FI				[Ff][Ii]
IF				[Ii][Ff]
IN				[Ii][Nn]
INHERITS		[Ii][Nn][Hh][Ee][Rr][Ii][Tt][Ss]
LET				[Ll][Ee][Tt]
LOOP			[Ll][Oo][Oo][Pp]
POOL			[Pp][Oo][Oo][Ll]
THEN			[Tt][Hh][Ee][Nn]
WHILE			[Ww][Hh][Ii][Ll][Ee]
CASE			[Cc][Aa][Ss][Ee]
ESAC			[Ee][Ss][Aa][Cc]
OF				[Oo][Ff]
NEW				[Nn][Ee][Ww]
ISVOID			[Ii][Ss][Vv][Oo][Ii][Dd]
NOT				[Nn][Oo][Tt]
TRUE			t[Rr][Uu][Ee]
FALSE			f[Aa][Ll][Ss][Ee]
NULL			(\0)
WHITESPACE		[ \t\f\r\v]+
PARENTHESIS_O	\(
PARENTHESIS_C	\)
PUNCTUATION		[@;:,\(\)\{\}\+\-\*/=~<\.]
ESCAPE			\\
DARROW         	=>
LE				<=
ASSIGN			<-
STRING			\"[^"\n]*["\n]
DQUOTE			\"
NEWLINE			(\n)

%x 	COMMENT_M STRING ESCAPE

%%


{CLASS} {
	yylval.sval=strdup(yytext);
	printf("%s\n",yytext);
	return CLASS;
}
{ELSE} {
    printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return ELSE;
}
{FI} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return FI;
}
{IF} {
	printf("%s\n",yytext);
    yylval.sval=strdup(yytext);
    return IF;
}
{IN} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return IN;
}
{INHERITS} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return INHERITS;
}
{LET} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return LET;
}
{LOOP} {
	printf("%s\n",yytext);
	yylval.sval=strdup(yytext);
    return LOOP;
}
{POOL} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return POOL;
}
{THEN} {
	printf("%s\n",yytext);
	yylval.sval=strdup(yytext);
    return THEN;
}
{WHILE} {
	printf("%s\n",yytext);
	yylval.sval=strdup(yytext);
    return WHILE;
}
{CASE} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return CASE;
}
{ESAC} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return ESAC;
}
{OF} {
	printf("%s\n",yytext);
	yylval.sval=strdup(yytext);
    return OF;
}
{NEW} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return NEW;
}
{ISVOID} {
	printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return ISVOID;
}
{NOT} {
	printf("%s\n",yytext);
	yylval.sval=strdup(yytext);
    return NOT;
}

{TRUE} {
printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return TRUE;
}

{FALSE} {
printf("%s\n",yytext);
    strcpy(yylval.sval, yytext);
    return FALSE;
}
{OBJ_ID} {
	//printf("OBJECT id:%s\n",yytext);
	yylval.sval=strdup(yytext);
    if(!lookup_entry_by_str(yytext, t))
    {
		node=create_entry(yytext,3,yylineno,5,0,"0");
		t=insert_entry(node,t);
		//printf("inserted\n");
    }
    return OBJECTID;
}
		 
{TYPE_ID} {
	printf("%s\n",yytext);
	strcpy(yylval.sval, yytext);
	if(!lookup_entry_by_str(yytext, t))
	{
		node=create_entry(yytext,3,yylineno,4,0,"0");
		t=insert_entry(node,t);
		//printf("inserted\n");
    }
    return TYPEID;
}

{STRING} {
/*printf("%s\n",yytext);
    BEGIN(INITIAL);
    if (string_buf_ptr < string_buf + MAX_STR_CONST) {
        *string_buf_ptr = '\0';
        return STR_CONST;
    } else {
        yylval.error_msg = "String constant too long";
        return ERROR;
    }*/
	yylval.sval = strdup(yytext);                
	if (yylval.sval[yyleng-1] != '"')                    
		printf("improperly terminated string\n");                
	else                    
		return STR_CONST;               
	printf("found '%s'\n", yylval.sval);
}
<STRING>{ESCAPE} {
printf("%s\n",yytext);
    BEGIN(ESCAPE);
}
<STRING>{NULL} {
printf("%s\n",yytext);
    yylval.error_msg = "String contains null character";
    return ERROR;
}
<STRING><<EOF>> {
printf("%s\n",yytext);
    yylval.error_msg = "EOF in string constant";
    return 0;
}
<STRING>{NEWLINE} {
    yylval.error_msg = "Unterminated string constant";
    return ERROR;
}
<ESCAPE>. {
printf("%s\n",yytext);
    char c = yytext[0];
    if (c == 't') {
        c = '\t';
    } else if (c == 'b') {
        c = '\b';
    } else if (c == 'n') {
        c = '\n';
    } else if (c == 'f') {
        c = '\f';
    }
    if (string_buf_ptr < string_buf + MAX_STR_CONST - 1) {
        *string_buf_ptr++ = c;
    }
    BEGIN(STRING);
}
<ESCAPE>{NEWLINE} {
    BEGIN(STRING);
}
<STRING>{STRING} {
	printf("%s\n",yytext);
    int remaining_size = MAX_STR_CONST - (string_buf_ptr - string_buf) - 1;
    int to_copy = yyleng > remaining_size ? remaining_size : yyleng;
    strcpy(string_buf_ptr, yytext);
    string_buf_ptr += to_copy;
}
    
{INTEGER} {
printf("%s\n",yytext);
    yylval.ival = atoi(yytext);
    return INT_CONST;
}
{DARROW} {
    return DARROW;
}
{PUNCTUATION} {
printf("%s\n",yytext);
    return yytext[0];
}
{LE} {
printf("%s\n",yytext);
    return LE;
}
{ASSIGN} {
printf("%s\n",yytext);
    return ASSIGN;
}
{WHITESPACE} {}

{COMMENT_M}
{
	printf("comment: %s\n",yytext);
}

. {
printf("%s\n",yytext);
    yylval.error_msg = "Unexpected character";
    return ERROR;
}

%%

int yywrap() { return 1;}
