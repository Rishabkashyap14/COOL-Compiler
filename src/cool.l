%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>
#include "cool.h"

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   

struct Table *t;
entry* node = NULL;

int yylex();
void yyerror(char* s);
char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;
//YYSTYPE yylval;
#include "y.tab.h"
int curr_lineno=1;
int mcomment_count; /* to handle nested multiline comments */
%}

INTEGER			[0-9]+
IDENTIFIER		[a-zA-Z][a-zA-Z0-9_]*
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
STRING			[^\n\"\\]+
DQUOTE			\"
NEWLINE			(\n)

%x 	COMMENT_M STRING ESCAPE

%%


{CLASS} {
	strcpy(yylval.sval, yytext);
	return CLASS;
}
{ELSE} {
    strcpy(yylval.sval, yytext);
    return ELSE;
}
{FI} {
    strcpy(yylval.sval, yytext);
    return FI;
}
{IF} {
    strcpy(yylval.sval, yytext);
    return IF;
}
{IN} {
    strcpy(yylval.sval, yytext);
    return IN;
}
{INHERITS} {
    strcpy(yylval.sval, yytext);
    return INHERITS;
}
{LET} {
    strcpy(yylval.sval, yytext);
    return LET;
}
{LOOP} {
    strcpy(yylval.sval, yytext);
    return LOOP;
}
{POOL} {
    strcpy(yylval.sval, yytext);
    return POOL;
}
{THEN} {
    strcpy(yylval.sval, yytext);
    return THEN;
}
{WHILE} {
    strcpy(yylval.sval, yytext);
    return WHILE;
}
{CASE} {
    strcpy(yylval.sval, yytext);
    return CASE;
}
{ESAC} {
    strcpy(yylval.sval, yytext);
    return ESAC;
}
{OF} {
    strcpy(yylval.sval, yytext);
    return OF;
}
{NEW} {
    strcpy(yylval.sval, yytext);
    return NEW;
}
{ISVOID} {
    strcpy(yylval.sval, yytext);
    return ISVOID;
}
{NOT} {
    strcpy(yylval.sval, yytext);
    return NOT;
}

{TRUE} {
    strcpy(yylval.sval, yytext);
    return TRUE;
}

{FALSE} {
    strcpy(yylval.sval, yytext);
    return FALSE;
}
		 
{TYPE_ID} {
	strcpy(yylval.sval, yytext);
	node=create_entry(yytext,3,yylineno,4,0,0);
	t=insert_entry(node,t);
    return TYPEID;
}
{OBJ_ID} {
    strcpy(yylval.sval, yytext);
	node=create_entry(yytext,3,yylineno,5,0,0);
	t=insert_entry(node,t);
    return OBJECTID;
}
{DQUOTE} {
    BEGIN(STRING);
    string_buf_ptr = string_buf;
}
<STRING>{DQUOTE} {
    BEGIN(INITIAL);
    if (string_buf_ptr < string_buf + MAX_STR_CONST) {
        *string_buf_ptr = '\0';
        return STR_CONST;
    } else {
        yylval.error_msg = "String constant too long";
        return ERROR;
    }
}
<STRING>{ESCAPE} {
    BEGIN(ESCAPE);
}
<STRING>{NULL} {
    yylval.error_msg = "String contains null character";
    return ERROR;
}
<STRING><<EOF>> {
    yylval.error_msg = "EOF in string constant";
    return 0;
}
<STRING>{NEWLINE} {
    yylval.error_msg = "Unterminated string constant";
    curr_lineno++;
    return ERROR;
}
<ESCAPE>. {
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
    curr_lineno++;
    BEGIN(STRING);
}
<STRING>{STRING} {
    int remaining_size = MAX_STR_CONST - (string_buf_ptr - string_buf) - 1;
    int to_copy = yyleng > remaining_size ? remaining_size : yyleng;
    strcpy(string_buf_ptr, yytext);
    string_buf_ptr += to_copy;
}
    
{INTEGER} {
    yylval.ival = atoi(yytext);
    return INT_CONST;
}
{DARROW} {
    return DARROW;
}
{PUNCTUATION} {
    return yytext[0];
}
{LE} {
    return LE;
}
{ASSIGN} {
    return ASSIGN;
}
{WHITESPACE} {}

. {
    yylval.error_msg = "Unexpected character";
    return ERROR;
}

%%

yywrap() { return 1;}