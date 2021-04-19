#include "typeChecking.h"
#include <stdio.h>
#include <string.h>
#include<malloc.h>
#include<errno.h>
#include<stdlib.h>
#include "y.tab.h"

CFG *initialize_graph()
{
//	if((CFG *g=(CFG*)malloc(sizeof(CFG)))==NULL)
//		yyerror("No memory");
	CFG *g=(CFG*)malloc(sizeof(CFG));
	g->root=NULL;
	g->nblocks=0;
	return g;
}

BB *initialize_bb()
{
//	if((BB *b=(BB*)malloc(sizeof(BB)))==NULL)
//		yyerror("No memory");
	BB *b=(BB*)malloc(sizeof(BB));
	b->bb=NULL;
	b->left=NULL;
	b->right=NULL;
	return b;
}

TAC *initialize_tac()
{
//	if((TAC *t=(TAC*)malloc(sizeof(TAC)))==NULL)
//		yyerror("No memory");
	TAC *t=(TAC*)malloc(sizeof(TAC));
	t->tacRow=NULL;
	t->nrows=0;
	return t;
}

CFG *create_cfg(TAC *t)
{
	CFG *g = initialize_graph();
	tac *cur=t->tacRow;
	BB *basic_block=initialize_bb();
	basic_block->bb=initialize_tac();
	while(cur!=NULL && (cur->oprtr->type == typeOpr || (cur->oprtr->type == typeId && strcmp(cur->oprtr->id.i,"Label"))))
	{
		tac *row=(tac *)malloc(sizeof(tac));
		row->oprtr=cur->oprtr;
		row->arg1=cur->arg1;
		row->arg2=cur->arg2;
		row->temp=cur->temp;
		if(basic_block->bb->nrows==0)
			basic_block->bb->tacRow = row;
		else
		{
			tac *cur_1 = basic_block->bb->tacRow;
			while((cur_1->next) != NULL)
				cur_1 = cur_1->next;
			cur_1->next=row;
		}
		basic_block->bb->nrows++;
		cur = cur->next;
	}
	printf("########## Basic Block ###########\n");
	int strRed1=strengthReduction(basic_block->bb);
	display_tac_table(basic_block->bb);
	int conProp1=constantPropagation(basic_block->bb);
	display_tac_table(basic_block->bb);
	int conFold1=constantFolding(basic_block->bb);
	display_tac_table(basic_block->bb);
	//int deadEli1=deadcodeElimination(basic_block->bb);
	//display_tac_table(basic_block->bb);
	int copyProp1=copyPropagation(basic_block->bb);
	display_tac_table(basic_block->bb);
	int commonSubExpr1=commonSubExprElimination(basic_block->bb);
	display_tac_table(basic_block->bb);
	//display_tac_table(basic_block->bb);
	g->root = basic_block;
	printf("########## Basic Block ###########\n");
	return g;
}
