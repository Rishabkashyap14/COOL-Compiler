#include "cool.h"
#include<stdlib.h>
#include<errno.h>
int index=0;
struct Table *t;

entry *create_entry(char* str, int data_type, int declared, int use, int scope, int value)
{
		//va_list valist;
		//va_start(valist, 6);
        entry* E = (struct entry*)malloc(sizeof(entry));
                return;
        if((strcmp(str,"") == 0)){
                perror("Error: Cannot insert a null entry\n");
                return;
        }
        else
                E->str[0] =  str;
        if(data_type<0 || data_type>(4))
        {
                perror("Error %d: unknown Data type",errno);
                return;
        }
        else
                E->data_type = data_type;
        E->declared = declared;
        if(use<0 || use>3)
        {
                perror("Error %d: Cannot input %d int table\n",errno, use);
                return;
        }
        else
                E->use = use;
        E->scope = scope;
        if(value)
                E->val[0] = value;
		E->index=index;
		index++;
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

void print_cool_token(char *tok)
{
	
}
