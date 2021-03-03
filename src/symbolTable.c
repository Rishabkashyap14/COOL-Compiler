#include "cool.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<errno.h>
int i=0;

table* initialize()
{
		table* t=(table*)malloc(sizeof(table));
        t->head = NULL;
        t->nentries = 0;
        return t;
}

entry *create_entry(char* str, int data_type, int declared, int use, int scope, char *value)
{
		printf("Creating table entry for %s\n",str);
        entry* E = (entry*)malloc(sizeof(entry));
        if((strcmp(str,"") == 0)){
                perror("Error: Cannot insert a null entry\n");
                return NULL;
        }
        else
                strcpy(E->str, str);
        if(data_type<0 || data_type>(4))
        {
                perror("Error: unknown Data type");
                return NULL;
        }
        else
                E->data_type = data_type;
        E->declared = declared;
        if(use<0 || use>5)
        {
                perror("Error: Cannot input into table\n");
                return NULL;
        }
        else
                E->use = use;
        E->scope = scope;
        if(value)
                strcpy(E->val, value);
		E->index=i;
		i++;
        return E;
}

table *insert_entry(entry *node, table *t)
{
	if(node==NULL)
	{
		//printf("oops\n");
		return t;
	}
	entry *cur=t->head;
	if(cur == NULL)
	{
		t->head = node;
		return t;
	}
	while(cur->next != NULL)
		cur = cur->next;
	cur->next = node;
	return t;
}

table *delete_entry(int i, table* t)
{
	if(i>t->nentries)
		return t;
	entry *cur=t->head;
	entry *prev=NULL;
	while(cur!=NULL)
	{
		if(cur->index==i)
		{
			if(cur==t->head)
				prev=t->head;
			prev->next=cur->next;
			cur->next=NULL;
			free(cur);
			t->nentries--;
			return t;
		}	
		prev=cur;
		cur=cur->next;
	}
}

int lookup_entry_by_str(char *str,table *t)
{
	entry* p = t->head;
	while(p != NULL)
	{
		if((strcmp(p->str,str)) == 0)
			return 1;
		else
			p = p->next;
	}
	return 0;
}

int lookup_entry_by_index(int index,table *t)
{
	entry* p = t->head;
	while(p != NULL)
	{
		if(p->index == index)
			return 1;
		else
			p = p->next;
	}
	return 0;
}

void print_cool_token(char *tok)
{
	
}

void display_table(table *t)
{
	entry *cur=t->head;
	printf("+-------+-------+-------+-------+-------+------+------+------+-------+-------+------+------+------+-------+\n");
	printf("|INDEX\t\t|DATA\t\t\t|DATA TYPE\t\t|DECLARED\t\t|USE\t\t|SCOPE\t\t|VALUE\t\t|\n");
	while(cur!=NULL)
	{
		printf("|%d\t\t|%s\t\t\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|%s\t\t|\n",cur->index,cur->str,cur->data_type,cur->declared,cur->use,cur->scope,cur->val);
		cur=cur->next;
	}
	printf("+-------+-------+-------+-------+-------+------+------+------+-------+-------+------+------+------+-------+\n");
	printf("For data type, we have 0 for bool 1 for int 2 for string 3 for identifier\n For USE, we have 0 for parameter, 1 for argument, 2 for return, 3 for method, 4 for classname, 5 object\n");
}
