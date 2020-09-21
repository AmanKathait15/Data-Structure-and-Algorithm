#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
} nodetype;

void enqueueu(nodetype **head, nodetype **tail,int num)
{
	nodetype *ptr = (nodetype*)malloc(sizeof(nodetype));	ptr->info = num; ptr->next = NULL;

	if((*head)==NULL)
	{
		(*head) = ptr; (*tail) = ptr;
	}
	else 
	{
		(*tail)->next = ptr; (*tail)=(*tail)->next;
	}
}

void dequeue(nodetype **head, nodetype **tail)
{
	if(*head == NULL)	printf("empty \n");
	else
	{
		printf("element pop is %d\n",(*head)->info);
		(*head) = (*head)->next;
	}
	if((*head)==NULL)	(*tail) = NULL;
}

void display(nodetype *head)
{
	while(head)
	{
		printf("%d ",head->info);
		head = head -> next;
	}	printf("\n");
}

int main()
{
	nodetype *head = NULL , *tail = NULL;

	for(int i=0; i<5; i++)
	{
		enqueueu(&head,&tail,i);
		display(head);
	}

	while(head)
	{
		dequeue(&head,&tail);
		display(head);
	}

	return 0;
}