#include "type.h"

int enqueue(PROC ** queue, PROC * p)
{
	PROC * pCurr = *queue, * pPrev = 0;
	
	if(*queue)
	{
		while((pCurr) && (p->priority <= pCurr->priority))
		{
			pPrev = pCurr;
			pCurr = pCurr->next;
		}
			
		p->next = pCurr;
		
		if(pPrev)
			pPrev->next = p;
		else
			*queue = p;
	}
	else
		*queue = p;
		
	return;
}

PROC * dequeue(PROC ** queue)
{
	PROC * temp = *queue;
	
	if(temp)
		*queue = temp->next;
	
	return temp;
}

int printList(char * name, PROC * p)
{
	PROC * pCurr = p;
	
	//Print the queue
	printf("%s = ", name);
	
	while(pCurr)
	{
		printf("[%d %d] -> ", pCurr->pid, pCurr->priority);
		
		pCurr = pCurr->next;
	}
	
	printf("NULL\n");
}
