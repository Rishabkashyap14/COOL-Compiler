%{
void yyerror (char *s);
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
Program ast_root;	      /* the result of the parse  */
int omerrs = 0;               /* number of errors in lexing and parsing */
%}

/* A union of all the types that can be the result of parsing actions. */
%union {
  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
  char *error_msg;
}


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

%start program
// Program definitions
program
	: %empty
	| program class
	| program class error { yyerrok; }
	;

// Class definitions
class
	: CLASS TYPE "{" features "}" ";"
		{
			compiler.classes.push_back(new Class($2, $4));
			compiler.classes.back()->location = @$;
		}
	| CLASS TYPE INHERITS TYPE "{" features "}" ";"
		{
			compiler.classes.push_back(new Class($2, $4, $6));
			compiler.classes.back()->location = @$;
		}
	;

features
	: %empty { $$ = new Features(); $$->location = @$;  }
	| features attribute ";" { $1->addAttribute($2); $$ = $1; }
	| features method ";" { $1->addMethod($2); $$ = $1; }
	;

// Class variables/symbols/attributes
attribute
	: symbol_declaration { $$ = new Attribute($1); $$->location = @$; }
	| symbol_declaration "<-" expression { $$ = new Attribute($1, $3); $$->location = @$; }
	;

symbol_declaration
	: IDENTIFIER ":" TYPE { $$ = new Symbol($1, $3); $$->location = @$; }
	;

// Method/function definitions
method
	: IDENTIFIER "(" ")" ":" TYPE "{" expression "}"
		{
			$$ = new Method($1, $5, $7);
			$$->location = @$;
		}
	| IDENTIFIER "(" init_arg_list ")" ":" TYPE "{" expression "}"
		{
			$$ = new Method($1, $6, $3, $8);
			$$->location = @$;
		}
	;

init_arg_list
	: symbol_declaration { $$.push_back($1); }
	| init_arg_list "," symbol_declaration { $1.push_back($3); }
	;


// Expressions
expression
	: "(" expression ")" { $$ = $2; }
	| constants { $$ = $1; }
	| identifiers { $$ = $1; }
	/*| assignment
	| dispatch
	| conditional
	| loop
	| "{" block "}"
	| let 
	| cases
	| NEW TYPE
	| ISVOID expression*/
	| arithmetic { $$ = $1; }
	| comparison { $$ = $1; }
	;


constants
	: INT_CONSTANT { $$ = new Expression($1, "Int"); $$->location = @$; }
	| BOOL_CONSTANT { $$ = new Expression($1, "Bool"); $$->location = @$; }
	| STRING_CONSTANT { $$ = new Expression($1, "String"); $$->location = @$; }
	;

identifiers
	: IDENTIFIER { $$ = new Expression($1); $$->location = @$; }
	| SELF { $$ = new Expression("self"); $$->location = @$; }
	;
