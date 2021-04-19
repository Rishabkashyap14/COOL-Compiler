#include "typeChecking.h"
#include <string.h>
#include <stdio.h>

int strengthReduction(TAC *t)
{
	tac *cur=t->tacRow;
	while(cur!=NULL)
	{
		if(cur->oprtr->opr.oper==42)
		{
			if(cur->arg1->i.value==2)
				cur->arg1=cur->arg2;
			else if(cur->arg2->i.value==2)
				cur->arg2=cur->arg1;
			cur->oprtr->opr.oper=43;
		}
		cur=cur->next;
	}
	return 0;
}

int constantPropagation(TAC *t)
{
	tac *cur=t->tacRow;
	while(cur!=NULL)
	{
		if(cur->oprtr->opr.oper==280 && cur->arg1->type==typeInt)
		{
			tac *con=cur->next;
			while(con!=NULL && strcmp(con->temp->id.i,cur->temp->id.i))
			{
				if(con->arg1!=NULL && !strcmp(con->arg1->id.i,cur->temp->id.i))
					con->arg1=cur->arg1;
				if(con->arg2!=NULL && !strcmp(con->arg2->id.i,cur->temp->id.i))
					con->arg2=cur->arg1;
				con=con->next;
			}
		}
		cur=cur->next;
	}
	return 0;
}

int constantFolding(TAC *t)
{
	tac *cur=t->tacRow;
	while(cur!=NULL)
	{
		if(cur->arg1!=NULL && cur->arg2!=NULL && cur->arg1->type==typeInt && cur->arg2->type==typeInt)
		{
			switch(cur->oprtr->opr.oper)
			{
				case '+':
					cur->arg1->i.value=cur->arg1->i.value+cur->arg2->i.value;
					break;
				case '-':
					cur->arg1->i.value=cur->arg1->i.value+cur->arg2->i.value;
					break;
				case '*':
					cur->arg1->i.value=cur->arg1->i.value*cur->arg2->i.value;
					break;
				case '/':
					cur->arg1->i.value=cur->arg1->i.value/cur->arg2->i.value;
					break;
			}
			cur->arg2=NULL;
			cur->oprtr->opr.oper=280;
		}
		cur=cur->next;
	}
	return 0;
}

int deadcodeElimination(TAC *t)
{
	tac *cur=t->tacRow;
	tac *prev=NULL;
	while(cur!=NULL)
	{
		tac *con=cur->next;
		while(con!=NULL)
		{
			if(con->arg1!=NULL && con->arg1->type==typeId && !strcmp(con->arg1->id.i,cur->temp->id.i))
				break;
			if(con->arg2!=NULL && con->arg2->type==typeId && !strcmp(con->arg2->id.i,cur->temp->id.i))
				break;
			con=con->next;
		}
		if(con==NULL && cur->oprtr->type == typeOpr)
		{
			if(cur==t->tacRow)
				t->tacRow=cur->next;
			else
			{
				prev->next=cur->next;
			}
		}
		prev=cur;
		cur=cur->next;
	}
	return 0;
}

int copyPropagation(TAC *t)
{
	tac *cur=t->tacRow;
	while(cur!=NULL)
	{
		if(cur->oprtr->opr.oper==280 && cur->arg1->type==typeId)
		{
			tac *con=cur->next;
			while(con!=NULL && strcmp(con->temp->id.i,cur->temp->id.i))
			{
				if(con->arg1!=NULL && con->arg1->type==typeId && !strcmp(con->arg1->id.i,cur->temp->id.i))
					con->arg1=cur->arg1;
				if(con->arg2!=NULL && con->arg2->type==typeId && !strcmp(con->arg2->id.i,cur->temp->id.i))
					con->arg2=cur->arg1;
				con=con->next;
			}
		}
		cur=cur->next;
	}
	//int i=deadcodeElimination(t);
	return 0;
}

int commonSubExprElimination(TAC *t)
{
	tac *cur=t->tacRow;
	while(cur!=NULL)
	{
		tac *con=cur->next;
		tac *prev=NULL;
		while(con!=NULL)
		{
			if(
((con->arg1==NULL && cur->arg1==NULL) && (con->arg2==NULL && cur->arg2==NULL)) ||
(con->arg1!=NULL && con->arg2!=NULL && cur->arg1!=NULL && cur->arg2!=NULL && con->arg1->type==cur->arg1->type && con->arg2->type==cur->arg2->type && con->oprtr->opr.oper==cur->oprtr->opr.oper))
			{
				if(((con->arg1->type==typeInt && con->arg1->i.value==cur->arg1->i.value)
				|| (con->arg1->type==typeId && !strcmp(con->arg1->id.i,cur->arg1->id.i))) &&
				((con->arg2->type==typeInt && con->arg2->i.value==cur->arg2->i.value)
				|| (con->arg2->type==typeId && !strcmp(con->arg2->id.i,cur->arg2->id.i))))
				{
				char *temp=con->temp->id.i;
				if(con==t->tacRow)
					t->tacRow=cur->next;
				prev->next=con->next;
				tac *replace=con->next;
				while(replace!=NULL)
				{
					if(replace->arg1!=NULL && replace->arg1->type==typeId && !strcmp(replace->arg1->id.i,temp))
						replace->arg1=cur->temp;
					if(replace->arg2!=NULL && replace->arg2->type==typeId && !strcmp(replace->arg2->id.i,temp))
						replace->arg2=cur->temp;
					replace=replace->next;
				}
			}
			}
			prev=con;
			con=con->next;
		}
		cur=cur->next;
	}
	return 0;
}
