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
	int i;                      /* subscript to sym array */ 
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
		str_con s;       /* constants */         
		idNodeType id;          /* identifiers */         
		oprNodeType opr;        /* operators */     
	}; 
} nodeType;

nodeType *bool_constant(char *value);
nodeType *int_constant(int value);
nodeType *str_constant(char *value);
nodeType *identifier(char *id);
nodeType *opr(int oper, int nops, ...); 
