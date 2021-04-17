%{
void yyerror (char *s);
#define YYDEBUG 1
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "cool.h"
#include "typeChecking.h"

extern FILE *yyin;	
int curr_lineno=0;
table *t;
int yylex();
extern entry* node;
int omerrs = 0;               /* number of errors in lexing and parsing */
%}

/* A union of all the types that can be the result of parsing actions. */
%union {
	char* sval;
	int ival;
	char *error_msg;
	nodeType *nval;
}

/* Types for the non-terminals */
%type <sval> program
%type <sval> class_list
%type <sval> class

%type <sval> feature
%type <sval> feature_list

%type <sval> formal
%type <sval> formals_list

%type <sval> expr opt_assign let_expr
%type <sval> exprs_semi exprs_comma 

%type <sval> case
%type <sval> cases

%token CLASS 258 ELSE 259 FI 260 IF 261 IFX 286 IN 262 
%token INHERITS 263 LET 264 LOOP 265 POOL 266 THEN 267 WHILE 268
%token CASE 269 ESAC 270 OF 271 DARROW 272 NEW 273 ISVOID 274
%token <sval>  STR_CONST 275 INT_CONST 276 
%token <sval> TRUE 277 FALSE 284
%token <sval>  TYPEID 278 OBJECTID 279 
%token ASSIGN 280 NOT 281 LE 282 ERROR 283

/*PRECEDENCE
The precedence of infix binary and prefix unary operations, from highest to lowest, is given by the following table:
* .	*@	*~	*isvoid	** /	*+ -	*<= < =	*not	*<-
All binary operations are left-associative, 
with the exception of assignment, which is right-associative,
and the three comparison operations, which do not associate. */
%right ASSIGN;
%left NOT;
%nonassoc "<" LE "=";
%left "+" "-";
%left "*" "/";
%left ISVOID;
%left "~";
%left "@";
%left ".";
%left PARENTHESIS_O PARENTHESIS_C
%%

/* RULE 1 */
/* program:=[class;]+ */
/* Program gives a list of classes */
program	: class_list
	{}
        ;
/*class list may be: */
class_list
	: class			/* single class */
	{$$=$<ival>1;}
	| error ';'
	| class_list class	/* several classes */
	{$$ = $<ival>2;}
	| class_list error ';'
	{}
	;


/* RULE 2 */ 
/* If no parent is specified, the class inherits from the Object class. */
/* class::= *class* TYPE [*inherits* TYPE] {[feature;]*}  */
class	: CLASS TYPEID '{' feature_list '}' ';'/*without inherits i.e. from Object Class */
		{ 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
	| CLASS TYPEID '{' '}' ';' /* without inherits or features */
		{ 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
	| CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'
		{ 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}
	| CLASS TYPEID INHERITS TYPEID '{' '}' ';' /* with inherits but no features */
		{ 
			curr_lineno++;
			//node=create_entry($2,3,curr_lineno,4,0,"0");
			//t=insert_entry(node,t);		   
		}	
	;

/* feature list formulation */
feature_list	: feature ';'	/*single feature */
		{$$=$1;}
		| error ';'	/*no features */
		| feature_list feature ';'	/*several features */
		{$$=$2;}
		| feature_list error ';'
		;

/* RULE 3 */
/* feature::= ID([formal[,formal]*]):TYPE{expr}	..(i)
	|	ID:TYPE[<-expr]			..(ii) */
feature	: OBJECTID '(' formals_list ')' ':' TYPEID '{' expr '}' /* For a method(i) */
	{$$=ex($1);}//,$3,$1,$6);}
	| OBJECTID '(' formals_list ')' ':' TYPEID '{' '}'	/* no expression */
	{$$=ex(NULL);}//,$3,$1,$6);}
	| OBJECTID '(' ')' ':' TYPEID '{' '}'			/* no formal parameters and expressions*/
	{$$=ex(NULL);}//,NULL,$1,$6);}
	| OBJECTID '(' ')' ':' TYPEID '{' expr '}'		/* no formal parameters */
	{$$=ex($7);}//,NULL,$1,$6);}
	| OBJECTID ':' TYPEID opt_assign			/* For an attribute(ii) */
	{	
		$$ = ex(opr(ASSIGN,3,identifier($1),$3,$4));/**/
	}
	;

/* RULE 4 */
/* formal::= ID:TYPE */
formal	: OBJECTID ':' TYPEID
	{
		$$=identifier($<sval>1);
	} 
	;

formals_list	: formal 
		{$$=$1;}
	     	| formals_list ',' formal 
		{$$ = opr(',', 2, NULL, NULL);}
		;

/* RULE 5 */
/*
expr::=  ID<-expr							assignment
	|expr[@TYPE].ID( [expr[[,expr]]∗] )				method of object being called optionally from a specific class
	|ID( [expr[[,expr]]∗] )						creating object
	|if expr then expr else expr fi					conditional
	|while expr loop expr pool					while loop
	| {[[expr; ]]+}							set of expressions separated by semi-colon in curly braces
	|let ID : TYPE [<-expr] [[,ID : TYPE [<-expr]]]∗in expr		let
	|case expr of [[ID : TYPE =>expr; ]]+ esac 			switch case
	|new TYPE							new
	|isvoid expr							isvoid
	|expr+expr							addition
	|expr−expr							subtraction
	|expr∗expr							multiplication
	|expr/expr							division
	|~expr								negate
	|expr<expr							less than
	|expr<=expr							less than equal to
	|expr=expr							equal
	|not expr							not
	|(expr)								parenthesis
	|ID|integer|string|true|false					values
*/
exprs_comma	: expr
		{$$=$1;}
		| exprs_comma ',' expr
		{$$ = opr(',', 2, NULL, $1);}
		;

exprs_semi	: expr ';'
		{$$=$1;}
		| exprs_semi expr ';'
		{$$ = ex(opr(';', 2,NULL,$2));}
		;

case	: OBJECTID ':' TYPEID DARROW expr ';'
	{$$=opr(DARROW,3,identifier($1),$3,$5);/*a:A<=(5+3);*/}
	;

cases 	: case
	{$$=$1;}
	| cases case
	{$$=$2;}
	;

opt_assign	: 
		| ASSIGN expr
		{
			$$=opr('=',1,$2);
		}
		;

let_expr	: OBJECTID ':' TYPEID opt_assign IN expr 
	 		%prec LET
		{$$ = opr(IN, 3, identifier($1),identifier($4),$<sval>5);}
		| OBJECTID ':' TYPEID opt_assign ',' let_expr
		{$$ = opr(LET, 3, identifier($1),identifier($4),$<sval>5);}
		| error ',' let_expr
		{$$=$3;}
		;

expr	: OBJECTID ASSIGN expr
	{$$=opr($<ival>2,2,$1,$3);}
	| expr '@' TYPEID '.' OBJECTID '(' ')'
	{	/*operator identified by @*/
		$$=opr($<sval>2,3,$1,$3,$5);
	}
	| expr '@' TYPEID '.' OBJECTID '(' exprs_comma ')'
	{
		/*operator identified by (*/
		$$=opr($<ival>6,3,$1,$5,$7);
	}
	| OBJECTID '(' ')'
		{ 
			curr_lineno++;
			node=create_entry($1,3,curr_lineno,5,0,"0");
			t=insert_entry(node,t);	
			/* operator identified by ' ' */
			$$=opr(' ',1,$1);	   
		}
	| OBJECTID '(' exprs_comma ')'
		{ 
			curr_lineno++;
			node=create_entry($1,3,curr_lineno,5,0,$3);
			t=insert_entry(node,t);
			/* operator identified by ')' */
			$$=opr(')',2,$1,$3);		   
		}
	| expr '.' OBJECTID '(' ')'
	{$$=opr('.',2,$1,$3);}
	| expr '.' OBJECTID '(' exprs_comma ')'
	{
		/*operator identified by a */
		$$=opr('a',3,$1,$3,$5);
	}
	| IF expr THEN expr ELSE expr FI
	{$$ = opr(IF, 3, $2, $4, $6);/**/}
	| WHILE expr LOOP expr POOL
	{$$ = opr(WHILE, 2, $2, $4);/**/}
	| '{' exprs_semi '}'
	{$$ = $2;}
	| '{' '}'
	| '{' error '}'
	| LET let_expr 
	{$$=$<ival>1;}
	| CASE expr OF cases ESAC
	{$$=opr(CASE,2,$2,$4);}
	| NEW TYPEID
	{$$=identifier($<sval>2);}
	| ISVOID expr
	{$$=opr($<ival>1,1,$2);}
	| expr '+' expr
	{$$=opr('+',2,$1,$3);/**/}
	| expr '-' expr
	{$$=opr('-',2,$1,$3);/**/}
	| expr '*' expr 
	{$$=opr('*',2,$1,$3);/**/}
	| expr '/' expr
	{$$=opr('/',2,$1,$3);/**/} 
	| '~' expr
	{$$=opr('~',1,$2);/**/}
	| expr '<' expr
	{$$=opr('<',2,$1,$3);/**/}
	| expr LE expr
	{$$=opr($<ival>2,2,$1,$3);/**/}
	| expr '=' expr
	{$$=opr(285,2,$1,$3);/**/}
	| NOT expr
	{$$=opr(NOT,1,$2);}
	| '(' expr ')'
	{$$=$2;}
	| OBJECTID 
	{
		printf("OBJECT ID: %s\n",$<sval>1);
		if(!strcmp($<sval>1,"else"))
			$$=identifier("b");
	}
	| STR_CONST
	{$$=str_constant($1);}
	| INT_CONST
	{$$=integer_constant($<ival>1);}
	| TRUE
	{$$=bool_constant($<sval>1);}
	| FALSE
	{$$=bool_constant($<sval>1);} 
	;

%%

void yyerror(char *s)
{
	fprintf(stderr,"%s\n",s);
	omerrs++;
	if(omerrs>50) 
 	{
 		fprintf(stdout, "More than 50 errors\n"); 
 		exit(1);
 	}
}
int main(int argc, char **argv)
{	
	t = initialize();
	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("Symbol Table:\n");
	display_table(t);
	return 0;
}
