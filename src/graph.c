/* source code courtesy of Frank Thomas Braun */
#include <stdio.h>
#include <string.h>
#include "cool.h"
#include "y.tab.h"
#include "typeChecker.h"
int del = 1; /* distance of graph columns */
int eps = 3; /* distance of graph lines */
/* interface for drawing (can be replaced by "real" graphic using GD or
other) */
void graphInit (void);
void graphFinish();
void graphBox (char *s, int *w, int *h);
void graphDrawBox (char *s, int c, int l);
void graphDrawArrow (int c1, int l1, int c2, int l2);
/* recursive drawing of the syntax tree */
void exNode (nodeType *p, int c, int l, int *ce, int *cm);
/***********************************************************/
/* main entry point of the manipulation of the syntax tree */
int ex (nodeType *p) {
	int rte, rtm;
	graphInit ();
	exNode (p, 0, 0, &rte, &rtm);
	graphFinish();
	return 0;
}

void exNode(nodeType *p,int c, int l,int *ce, int *cm)
{
	int w, h; //node width and height 
	char *s; //node text
	int cbar; // "real" start column of node (centred above subnodes)
	int k; //child number
	int che, chm; //end column and mid of children
	int cs; // start column of children
	char word[20]; // extended node text
	
	if (!p) 
		return;
	strcpy (word, "???"); /* should never appear */
	s = word;
	switch(p->type) {
		case typeCon: sprintf (word, "c(%d)", p->con.value); break;
		case typeId: sprintf (word, "id(%c)", p->id.i + 'A'); break;
		case typeOpr:
			switch(p->opr.oper){
			case WHILE:
				s = "while"; 
				break;
			case IF:
				s = "if";
				break;
			case PRINT:
				s = "print"; 
				break;
			case ';':
				s = "[;]";
				break;
			case '=':
				s = "[=]";
				break;
			case UMINUS:
				s = "[_]";
				break;
			case '+':
				s = "[+]";
				break;
			case '-':
				s = "[-]";
				break;
			case '*':
				s = "[*]";
				break;
			case '/':
				s = "[/]";
				break;
			case '<':
				s = "[<]";
				break;
			case '>':
				s = "[>]";
				break;
			case GE:
				s = "[>=]";
				break;
			case LE:
				s = "[<=]";
				break;
			case NE:
				s = "[!=]";
				break;
			case EQ:
				s = "[==]";
				break;
		}
		break;	
	}
	
	/* construct node text box */
	graphBox (s, &w, &h);
	cbar = c;
	*ce = c + w;
	*cm = c + w / 2;
	
	/* node is leaf */
	if (p->type == typeCon || p->type == typeId || p->opr.nops == 0) 
	{
		graphDrawBox (s, cbar, l);
		return;
	}
	
	/* node has children */
	cs = c;
	for (k = 0; k < p->opr.nops; k++) 
	{
		exNode (p->opr.op[k], cs, l+h+eps, &che, &chm);
		cs = che;
	}
	
	/* total node width */
	if (w < che - c) 
	{
		cbar += (che - c - w) / 2;
		*ce = che;
		*cm = (c + che) / 2;
	}
	
	/* draw node */
	graphDrawBox (s, cbar, l);
	/* draw arrows (not optimal: children are drawn a second time) */
	cs = c;
	for (k = 0; k < p->opr.nops; k++) 
	{
		exNode (p->opr.op[k], cs, l+h+eps, &che, &chm);
		graphDrawArrow (*cm, l+h, chm, l+h+eps-1);
		cs = che;
	}
}
	
	
	
	
	
	
	
	
	
