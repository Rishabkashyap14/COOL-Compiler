#include <stdio.h>

/* 1.Symbol-table related */
/*1.1) Structure definitions */
/* Symbol table will be stored as a linked list(table) of nodes(entry) */
/*A) entry */
typedef struct Entry
{
	char str[125]; //name
	char val[1025]; //value
	int size; 
	int index; //unique identification
	int data_type; //0 for bool 1 for int 2 for string 3 for identifier
	int scope;
	int declared; //Line of declaration
	int referred; //Line of reference
	int use; //0 for parameter, 1 for argument, 2 for return, 3 for method, 4 for classname, 5 object
	struct Entry *next; 
}entry;
/*B) Linked list */
typedef struct Table
{
	entry *head;
	int nentries; //number of entries	
}table;

/*C) Functions */
table* initialize();
table *create_table(void);
entry *create_entry(char *str,int data_type,int declared,int use, int scope, char *value);
int lookup_entry_by_str(char *str,table *t);//return index of entry if found else return -1
int lookup_entry_by_index(int index,table *t);
table *insert_entry(entry *node,table *t);
table *delete_entry(int i, table* t);
void display_table(table *t);





