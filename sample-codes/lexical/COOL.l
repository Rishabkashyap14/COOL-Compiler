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
COMMENT_M		
