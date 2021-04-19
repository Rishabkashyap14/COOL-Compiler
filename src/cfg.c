#include "typeChecking.h"
#include <stdio.h>
#include "y.tab.h"

CFG *initialize_graph()
{
	if(CFG *g=malloc(sizeof(CFG))==NULL)
		yyerror("No memory");
	
}
