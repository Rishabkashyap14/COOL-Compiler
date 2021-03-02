#include "cool.h"

table *insert_entry(entry *node, table *t)
{
	if(node==NULL)
		return t;
	entry *cur=t->head;
	while(cur->next!=NULL)
		cur=cur->next;
	cur->next=node;
	return t;
}
