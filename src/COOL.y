%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>
#include "cool.h"

extern FILE *yyin;	/* Findout where this is */
int curr_lineno=0;
extern table *t;
int yylex();
extern entry* node;
int omerrs = 0;               /* number of errors in lexing and parsing */
%}

/* A union of all the types that can be the result of parsing actions. */
%union {
	char* sval;
	int ival;
	char *error_msg;
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

%token CLASS 258 ELSE 259 FI 260 IF 261 IN 262 
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
program	: class_list	/*{ ast_root = program($1); parse_results = $1; }*/
        ;
/*class list may be: */
class_list
	: class			/* single class */
		/*{ $$ = single_Classes($1);  }*/
	| error ';'
		/*{ $$ = nil_Classes();  }*/
	| class_list class	/* several classes */
		/*{ $$ = append_Classes($1,single_Classes($2)); }*/
	| class_list error ';'
		/*{ $$ = append_Classes($1,nil_Classes()); }*/
	;


/* RULE 2 */ 
/* If no parent is specified, the class inherits from the Object class. */
/* class::= *class* TYPE [*inherits* TYPE] {[feature;]*}  */
class	: CLASS TYPEID '{' feature_list '}' ';'/*without inherits i.e. from Object Class */
		{ 
			curr_lineno++;
			node=create_entry($2,3,curr_lineno,4,0,"0");
			t=insert_entry(node,t);		   
		}
		/*{  $$ = class_($2,idtable.add_string("Object"),$4,stringtable.add_string(curr_filename)); }*/
	| CLASS TYPEID '{' '}' ';' /* without inherits or features */
		{ 
			curr_lineno++;
			node=create_entry($2,3,curr_lineno,4,0,"0");
			t=insert_entry(node,t);		   
		}
		/*{  $$ = class_($2,idtable.add_string("Object"),nil_Features(),stringtable.add_string(curr_filename)); }*/ 
	| CLASS TYPEID INHERITS TYPEID '{' feature_list '}' ';'
		{ 
			curr_lineno++;
			node=create_entry($2,3,curr_lineno,4,0,"0");
			t=insert_entry(node,t);		   
		}
		/*{  $$ = class_($2,$4,$6,stringtable.add_string(curr_filename)); }*/
	| CLASS TYPEID INHERITS TYPEID '{' '}' ';' /* with inherits but no features */
		{ 
			curr_lineno++;
			node=create_entry($2,3,curr_lineno,4,0,"0");
			t=insert_entry(node,t);		   
		}
		/*
		{  $$ = class_($2,$4,nil_Features(),stringtable.add_string(curr_filename)); }
		*/
	;

/* feature list formulation */
feature_list	: feature ';'	/*single feature */
			/*{ $$ = single_Features($1); }*/
		| error ';'	/*no features */
			/*{ $$ = nil_Features(); }*/
		| feature_list feature ';'	/*several features */
			/*{ $$ = append_Features($1, single_Features($2)); }*/
		| feature_list error ';'
			/*{ $$ = append_Features($1, nil_Features()); }*/
		;

/* RULE 3 */
/* feature::= ID([formal[,formal]*]):TYPE{expr}	..(i)
	|	ID:TYPE[<-expr]			..(ii) */
feature	: OBJECTID '(' formals_list ')' ':' TYPEID '{' expr '}' /* For a method(i) */
		/*{ $$ = method($1, $3, $6, $8); }*/
	| OBJECTID '(' formals_list ')' ':' TYPEID '{' '}'	/* no expression */
		/*{ $$ = method($1, $3, $6, no_expr()); }*/ 
	| OBJECTID '(' ')' ':' TYPEID '{' '}'			/* no formal parameters and expressions*/
		/*{ $$ = method($1, nil_Formals(), $5, no_expr()); }*/ 
	| OBJECTID '(' ')' ':' TYPEID '{' expr '}'		/* no formal parameters */
		/*{ $$ = method($1, nil_Formals(), $5, $7); }*/ 
	| OBJECTID ':' TYPEID opt_assign			/* For an attribute(ii) */
		/*{ $$ = attr($1, $3, $4); }*/
	;

/* RULE 4 */
/* formal::= ID:TYPE */
formal	: OBJECTID ':' TYPEID 
       		/*{ $$ = formal($1, $3); }*/
	;

formals_list	: formal 
	     		/*{ $$ = single_Formals($1); }*/
	     	| formals_list ',' formal 
			/*{ $$ = append_Formals($1, single_Formals($3)); }*/
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
	    		/*{ $$ = single_Expressions($1); }*/
		| exprs_comma ',' expr
			/*{ $$ = append_Expressions($1, single_Expressions($3)); }*/
		;

exprs_semi	: expr ';'
			/*{ $$ = single_Expressions($1); }*/
		| exprs_semi expr ';'
			/*{ $$ = append_Expressions($1, single_Expressions($2)); }*/
		;

case	: OBJECTID ':' TYPEID DARROW expr ';'
     		/*{ $$ = branch($1, $3, $5); }*/
	;

cases 	: case
       		/*{ $$ = single_Cases($1); }*/
	| cases case
		/*{ $$ = append_Cases($1, single_Cases($2)); }*/
	;

opt_assign	: /* empty */
		    	/*{ $$ = no_expr(); }*/
		| ASSIGN expr
			/*{ $$ = $2; }*/
		;

let_expr	: OBJECTID ':' TYPEID opt_assign IN expr 
	 		%prec LET
	 		/*{ $$ = let($1, $3, $4, $6); }*/
		| OBJECTID ':' TYPEID opt_assign ',' let_expr
			/*{ $$ = let($1, $3, $4, $6); }*/
		| error ',' let_expr
			/*{ $$ = $3; }*/
		;

expr	: OBJECTID ASSIGN expr
     		/*{ $$ = assign($1, $3); }*/
	| expr '@' TYPEID '.' OBJECTID '(' ')'
		/*{ $$ = static_dispatch($1, $3, $5, nil_Expressions()); }*/
	| expr '@' TYPEID '.' OBJECTID '(' exprs_comma ')'
		/*{ $$ = static_dispatch($1, $3, $5, $7); }*/
	| OBJECTID '(' ')'
		{ 
			curr_lineno++;
			node=create_entry($1,3,curr_lineno,5,0,"0");
			t=insert_entry(node,t);		   
		}
		/*{ $$ = dispatch(object(idtable.add_string("self")), $1, nil_Expressions()); }*/
	| OBJECTID '(' exprs_comma ')'
		{ 
			curr_lineno++;
			node=create_entry($1,3,curr_lineno,5,0,$3);
			t=insert_entry(node,t);		   
		}
		/*{ $$ = dispatch(object(idtable.add_string("self")), $1, $3); }*/
	| expr '.' OBJECTID '(' ')'
		/*{ $$ = dispatch($1, $3, nil_Expressions()); }*/
	| expr '.' OBJECTID '(' exprs_comma ')'
		/*{ $$ = dispatch($1, $3, $5); }*/
	| IF expr THEN expr ELSE expr FI
		/*{ $$ = cond($2, $4, $6); }*/
	| WHILE expr LOOP expr POOL
		/*{ $$ = loop($2, $4); }*/
	| '{' exprs_semi '}'
		/*{ $$ = block($2); }*/
	| '{' '}'
		/*{ $$ = no_expr(); }*/
	| '{' error '}'
		/*{ $$ = no_expr(); }*/
	| LET let_expr 
		/*{ $$ = $2; }*/
	| CASE expr OF cases ESAC
		/*{ $$ = typcase($2, $4); }*/
	| NEW TYPEID
		/*{ $$ = new_($2); }*/
	| ISVOID expr
		/*{ $$ = isvoid($2); }*/
	| expr '+' expr
		/*{ $$ = plus($1, $3); }*/
	| expr '-' expr
		/*{ $$ = sub($1, $3); }*/
	| expr '*' expr 
		/*{ $$ = mul($1, $3); }*/
	| expr '/' expr 
		/*{ $$ = divide($1, $3); }*/
	| '~' expr
		/*{ $$ = neg($2); }*/
	| expr '<' expr
		/*{ $$ = lt($1, $3); }*/
	| expr LE expr
		/*{ $$ = leq($1, $3); }*/
	| expr '=' expr
		/*{ $$ = eq($1, $3); }*/
	| NOT expr
		/*{ $$ = comp($2); }*/
	| '(' expr ')'
		/*{ $$ = $2; }*/ 
	| OBJECTID 
     		/*{ $$ = object($1); }*/
	| STR_CONST
		/*{ $$ = string_const($1); }*/
	| INT_CONST
		/*{ $$ = int_const($1); }*/
	| TRUE
		/*{ $$ = bool_const($1); }*/ 
	| FALSE
		/*{ $$ = bool_const($1); }*/ 
	; 

/* end of grammar */
%%
/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s)
{

  /*cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
    << s << " at or near ";
  print_cool_token(yychar);
  cerr << endl;*/
 fprintf(stderr,"line %d: %s\n",curr_lineno,s);
  omerrs++;

  if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
}
int main(int argc, char **argv)
{	
	printf("Inside main\n");
	FILE * fp= fopen(argv[1], "r");
	yyin = fp;
	printf("Read the input file, continue with Lexing and Parsing\n");
	printf("Performing Lexical analysis......\n\n");
	yyparse ( );
	printf("\n\033[0;32mParsing completed.\033[0m\n\n");
	printf("Symbol Table after Lexical Analysis: \n");
	display_table(t);
	return 0;
}
