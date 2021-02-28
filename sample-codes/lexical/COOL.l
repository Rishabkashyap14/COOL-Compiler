%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>


extern int lex_verbose;

#define LOG_LEVEL 1
#define LOGE \
if (lex_verbose) { \
    printf("Scanned error: %s\n", yylval.error_msg); \
}
#define LOG(msg) \
if (lex_verbose) { \
    printf("%s\n",msg); \
}
#define LOGS(token) \
if (lex_verbose) { \
    printf("Scanned symbol '%d': %s\n", #token, yylval.symbol); \
}
#define LOGB \
if (lex_verbose) { \
    printf("Scanned boolean '%c': %s\n", yylval.boolean, yytext); \
}
#define LOGT(token) \
if (lex_verbose) { \
    printf("Scanned token '%d': %s\n", #token, yytext); \
}
/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep gcc happy */



char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;
extern YYSTYPE yylval;
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
FI			[Ff][Ii]
IF			[Ii][Ff]
IN			[Ii][Nn]
INHERITS		[Ii][Nn][Hh][Ee][Rr][Ii][Tt][Ss]
LET			[Ll][Ee][Tt]
LOOP			[Ll][Oo][Oo][Pp]
POOL			[Pp][Oo][Oo][Ll]
THEN			[Tt][Hh][Ee][Nn]
WHILE			[Ww][Hh][Ii][Ll][Ee]
CASE			[Cc][Aa][Ss][Ee]
ESAC			[Ee][Ss][Aa][Cc]
OF			[Oo][Ff]
NEW			[Nn][Ee][Ww]
ISVOID			[Ii][Ss][Vv][Oo][Ii][Dd]
NOT			[Nn][Oo][Tt]
TRUE			t[Rr][Uu][Ee]
FALSE			f[Aa][Ll][Ss][Ee]
NULL			(\0)
WHITESPACE		[ \t\f\r\v]+
PARENTHESIS_O		\(
PARENTHESIS_C		\)
FLOWER_O		\{
FLOWER_C		\}
SQUARE_O		\[
SQUARE_C		\]
PUNCTUATION		[@;:,\(\)\{\}\+\-\*/=~<\.]
ESCAPE			\\
DARROW          	=>
LE			<=
ASSIGN			<-
STRING			[^\n\"\\]+
DQUOTE			\"
NEWLINE			(\n)

%x 	COMMENT_M STRING ESCAPE

%%

{CLASS} {
    LOGT(CLASS);
    return CLASS;
}
{ELSE} {
    LOGT(ELSE);
    return ELSE;
}
{FI} {
    LOGT(FI);
    return FI;
}
{IF} {
    LOGT(IF);
    return IF;
}
{IN} {
    LOGT(IN);
    return IN;
}
{INHERITS} {
    LOGT(INHERITS);
    return INHERITS;
}
{LET} {
    LOGT(LET);
    return LET;
}
{LOOP} {
    LOGT(LOOP);
    return LOOP;
}
{POOL} {
    LOGT(POOL);
    return POOL;
}
{THEN} {
    LOGT(THEN);
    return THEN;
}
{WHILE} {
    LOGT(WHILE);
    return WHILE;
}
{CASE} {
    LOGT(CASE);
    return CASE;
}
{ESAC} {
    LOGT(ESAC);
    return ESAC;
}
{OF} {
    LOGT(OF);
    return OF;
}
{NEW} {
    LOGT(NEW);
    return NEW;
}
{ISVOID} {
    LOGT(ISVOID);
    return ISVOID;
}
{NOT} {
    LOGT(NOT);
    return NOT;
}

{TRUE} {
    LOGB;
    return TRUE;
}

{FALSE} {
    LOGB;
    return FALSE;
}
		 
{TYPE_ID} {
    yylval.symbol = idtable.add_string(yytext,yyleng);
    LOGS(TYPEID);
    return TYPEID;
}
{OBJ_ID} {
    yylval.symbol = idtable.add_string(yytext,yyleng);
    LOGS(OBJECTID);
    return OBJECTID;
}
{DQUOTE} {
    LOGT("Start of string");
    BEGIN(STRING);
    string_buf_ptr = string_buf;
}
<STRING>{DQUOTE} {
    BEGIN(INITIAL);
    if (string_buf_ptr < string_buf + MAX_STR_CONST) {
        *string_buf_ptr = '\0';
        cool_yylval.symbol = stringtable.add_string(string_buf);
	LOGS(STR_CONST);
        return STR_CONST;
    } else {
        cool_yylval.error_msg = "String constant too long";
	LOGE;
        return ERROR;
    }
}
<STRING>{ESCAPE} {
    BEGIN(ESCAPE);
}
<STRING>{NULL} {
    cool_yylval.error_msg = "String contains null character";
    LOGE;
    return ERROR;
}
<STRING><<EOF>> {
    cool_yylval.error_msg = "EOF in string constant";
    LOGE;
    return 0;
}
<STRING>{NEWLINE} {
    cool_yylval.error_msg = "Unterminated string constant";
    LOGE;
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
    strcpy(string_buf_ptr, yytext, to_copy);
    string_buf_ptr += to_copy;
}
    
{INTEGER} {
    yylval.symbol = inttable.add_string(yytext);
    LOGS(INT_CONST)
    return INT_CONST;
}
{DARROW} {
    LOGT(DARROW);
    return DARROW;
}
{PUNCTUATION} {
    LOGT();
    return yytext[0];
}
{LE} {
    LOGT(LE)
    return LE;
}
{ASSIGN} {
    LOGT(ASSIGN)
    return ASSIGN;
}
{WHITESPACE} LOGT(WHITESPACE);
. {
    yylval.error_msg = "Unexpected character";
    LOGE;
    return ERROR;
}

%%

int main(void)
{
	yylex();
}

yywrap() { return 1;}
