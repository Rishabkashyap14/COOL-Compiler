#include "typeChecking.h"
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

CFG *initialize_graph()
{
	if(CFG *g=malloc(sizeof(CFG))==NULL)
		yyerror("No memory");
	g->root=NULL;
	g->nblocks=0;
	return g;
}

BB *initialize_bb()
{
	if(BB *b=malloc(sizeof(BB))==NULL)
		yyerror("No memory");
	b->bb=NULL;
	b->left=NULL;
	b->right=NULL;
	return b;
}

TAC *initialize_tac()
{
	if(TAC *t=malloc(sizeof(TAC))==NULL)
		yyerror("No memory");
	t->tacRow=NULL;
	t->nrows=0;
	return t;
}

CFG *create_cfg(TAC *t)
{
	g=initialize_graph();
	tac *cur=t->tacRow;
	BB *basic_block=initialize_bb();
	while(cur!=NULL && strcmp(cur->oprtr->id.i,"Label"))
	{
		basic_block->bb=initialize_tac();
		tac *row=(tac *)malloc(sizeof(tac));
		row->oprtr=cur->oprtr;
		row->arg1=cur->arg1;
		row->arg2=cur->arg2;
		row->temp=cur->temp;
		if(table->nrows==0)
			tactable->tacRow=row;
					else
					{
						tac *cur=tactable->tacRow;
						while(cur->next!=NULL)
							cur=cur->next;
						cur->next=row;
					}
					tactable->nrows++;  
	}
}
