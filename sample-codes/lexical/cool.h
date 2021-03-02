/*Token Names: Change numbers according to y file? */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define NEW 273
#define ISVOID 274
#define NOT 17
#define TRUE 18
#define FALSE 19
#define TYPEID 20
#define OBJECTID 21
#define DARROW 272 
#define ASSIGN 24
#define LE 25
#define ERROR 26
#define LET_STMT 27

/* Parse-tree related */

/* 1.Symbol-table related */
/*1.1) Structure definitions */
/* Symbol table will be stored as a linked list(table) of nodes(entry) */
/*A) entry */
struct Entry
{
	char str[1025]; //value
	int len; //length of the string without the trailing \0
	int index; //unique identification
}entry;
/*B) Linked list */
struct Table
{
	entry *head;
	int nentries; //number of entries	
}table;





