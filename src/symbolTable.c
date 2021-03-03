#include "cool.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<errno.h>
int i=0;
table *t;
//t->head=NULL;
//t->nentries=0;

entry *create_entry(char* str, int data_type, int declared, int use, int scope, char *value)
{
		//va_list valist;
		//va_start(valist, 6);
	printf("Creating table entry for %s\n",str);
        entry* E = (entry*)malloc(sizeof(entry));
                return NULL;
        if((strcmp(str,"") == 0)){
                perror("Error: Cannot insert a null entry\n");
                return NULL;
        }
        else
                strcpy(E->str,str);
        if(data_type<0 || data_type>(4))
        {
                perror("Error: unknown Data type");
                return NULL;
        }
        else
                E->data_type = data_type;
        E->declared = declared;
        if(use<0 || use>3)
        {
                perror("Error: Cannot input into table\n");
                return NULL;
        }
        else
                E->use = use;
        E->scope = scope;
        if(value)
                strcpy(E->val,value);
		E->index=i;
		i++;
        return E;
}

table *insert_entry(entry *node, table *t)
{
	if(node==NULL)
		return t;
	entry *cur=t->head;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=node;
	t->nentries++;
	return t;
}

table *delete_entry(int i)
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
		if(!(strcmp(p->str,str)))
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
	while(cur!=NULL)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%s\n",cur->str,cur->data_type,cur->declared,cur->use,cur->scope,cur->val);
		cur=cur->next;
	}
}
