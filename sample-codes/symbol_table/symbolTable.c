#include "cool.h"
int index=0;
entry *create_entry(char* str, int data_type, int declared, int use, int scope=0, ...)
{
	va_list valist;
	va_start(valist, 6);
        if((entry* E = (struct entry*)malloc(sizeof(entry))) == NULL)
                return;
        if((strcmp(str,"") == 0){
                perror("Error %d: Cannot insert a null entry\n",errno);
                return;
        }
        else
                E->str =  str;
        if(data_type<0 || data_type>(4))
        {
                perror(Error %d: unknown Data type",errno);
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
        if(valist[arg_count])
                E->value= valist[arg_count];
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
	if(i>nentries)
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

void print_cool_token(char *tok) // TO DO
{
	
}

int lookup_entry_by_str(char *str,table *t) //return index of entry if found else return -1
{
    if(t->head==NULL)
        return(-1);
    entry *curr = t->head;
    while(curr!=NULL)
    {
        if(curr->str == str)
            return(curr->index);
        curr=curr->next;
    }
    return(-1);
}
int lookup_entry_by_index(int index,table *t)
{
    if(t->head==NULL)
        return(-1);
    entry *curr = t->head;
    while(curr!=NULL)
    {
        if(curr->index == index)
            return(curr->value);
        curr=curr->next;
    }
    return(-1);
}
