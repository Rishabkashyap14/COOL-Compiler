#include <stdbool.h>

typedef enum { typeInt, typeStr, typeBool, typeId, typeOpr } nodeEnum;

 /* constants */ 

typedef struct {
	int value;
} int_con;

typedef struct {
	char *value;
} str_con;

typedef struct {
	bool value;
} bool_con;

/* identifiers */ 
typedef struct {     
	char *i;                      /* subscript to sym table */ 
} idNodeType; 

/* operators */ 
typedef struct {
	int oper;                   /* operator */     
	int nops;                   /* number of operands */     
	struct nodeTypeTag **op;    /* operands */ 
} oprNodeType; 

typedef struct nodeTypeTag {     
	nodeEnum type;              /* type of node */     
	union {         
		bool_con b;
		int_con i; 
		str_con s;       	/* constants */         
		idNodeType id;          /* identifiers */         
		oprNodeType opr;        /* operators */     
	}; 
} nodeType;

typedef struct tacRow {
	struct nodeTypeTag *oprtr;
	struct nodeTypeTag *arg1;
	struct nodeTypeTag *arg2;
	struct nodeTypeTag *temp;
	struct tacRow *next;
}tac;

typedef struct tacTable {
	tac *tacRow;
	int nrows;
}TAC;

typedef struct basicBlock {
	TAC *bb;
	struct basicBlock *left;
	struct basicBlock *right;
}BB;

typedef struct controlFlowGraph {
	BB *root;
	int nblocks;
}CFG;

nodeType *bool_constant(char *value);
nodeType *integer_constant(int value);
nodeType *str_constant(char *value);
nodeType *identifier(char *id);
nodeType *opr(int oper, int nops, ...); 
nodeType *ex(nodeType *p);
int exGraph(nodeType *p);
void display_tac_table(TAC *t);
int strengthReduction(TAC *t);
int constantPropagation(TAC *t);
int constantFolding(TAC *t);
int deadcodeElimination(TAC *t);
int copyPropagation(TAC *t);
int commonSubExprElimination(TAC *t);
