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
extern YYSTYPE cool_yylval;
int curr_lineno=1;
int mcomment_count; /* to handle nested multiline comments */
%}

INT			[0-9]+
IDENTIFIER		[a-zA-Z][a-zA-Z0-9_]*
TYPE_ID			[A-Z][a-zA-Z0-9_]*
OBJ_ID			[a-z][a-zA-Z0-9_]*
COMMENT_S		"--".*
COMMENT_M1		[\(\)\*]|[^\(\)\*\n]+
COMMENT_M2		(\*).*(\*)
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
WHITESPACE		[ \t\n\f\r\v]+
PARENTHESIS_O		\(
PARENTHESIS_C		\)
FLOWER_O		\{
FLOWER_C		\}
SQUARE_O		\[
SQUARE_C		\]
PUNCTUATION		[@;:,\(\)\{\}\+\-\*/=~<\.]
ESCAPE_SEQ		\\
DARROW          	=>
LE			<=
ASSIGN			<-
STRING			[^\n\"\\]+

