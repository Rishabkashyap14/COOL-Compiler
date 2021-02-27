%{
#include<cstdlib>
#include<cerrno>
#include<climits>
#include<string>

extern int lex_verbose;

#define LOG_LEVEL 1
#define LOGE \
if (lex_verbose) { \
    cout << "Scanned error: '" << yylval.error_msg << "'\n"; \
}
#define LOG(msg) \
if (lex_verbose) { \
    cout << msg << endl; \
}
#define LOGS(token) \
if (lex_verbose) { \
    cout << "Scanned symbol " << #token << ": '" << yylval.symbol << "'\n"; \
}
#define LOGB \
if (lex_verbose) { \
    cout << "Scanned boolean " << yylval.boolean << ": '" << yytext << "'\n"; \
}
#define LOGT(token) \
if (lex_verbose) { \
    cout << "Scanned token " << #token << ": '" << yytext << "'\n"; \
}
/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern YYSTYPE cool_yylval;
int curr_lineno=1;
int mcomment_count; /* to handle nested multiline comments */
%}

SCOMMENT	--.* 
MCOMMENT	[\(\)\*]|[^\(\)\*\n]+
MCOMMENT_START	\(\*
MCOMMENT_END	\*\)
NEWLINE		\n
DQUOTE		\"
ESCAPE		\\
NULL_CHAR	\0
INTEGER		[0-9]+
WS		[ \r\t\v\f]+
PUNCTUATION	[@;:,\(\)\{\}\+\-\*/=~<\.]
DARROW          =>
LE		<=
ASSIGN		<-
STRING		[^\n\"\\]+
TYPEID		[A-Z][A-Za-z0-9_]*
OBJECTID	[a-z][A-Za-z0-9_]* 
BOOL		t[Rr][Uu][Ee]|f[Aa][Ll][Ss][Ee]
CLASS           [Cc][Ll][Aa][Ss][Ss]
ELSE		[Ee][Ll][Ss][Ee]
FI		[Ff][Ii]
IF		[Ii][Ff]
IN		[Ii][Nn]
INHERITS	[Ii][Nn][Hh][Ee][Rr][Ii][Tt][Ss]
LET		[Ll][Ee][Tt]
LOOP		[Ll][Oo][Oo][Pp]
POOL		[Pp][Oo][Oo][Ll]
THEN		[Tt][Hh][Ee][Nn]
WHILE		[Ww][Hh][Ii][Ll][Ee]
CASE		[Cc][Aa][Ss][Ee]
ESAC		[Ee][Ss][Aa][Cc]
OF		[Oo][Ff]
NEW		[Nn][Ee][Ww]
ISVOID		[Ii][Ss][Vv][Oo][Ii][Dd]
NOT		[Nn][Oo][Tt]
%x MCOMMENT STRING ESCAPE


%%

