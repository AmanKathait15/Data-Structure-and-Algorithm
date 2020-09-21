#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
} nodetype;

void push(nodetype **top, int num)
{
	nodetype *ptr = (nodetype*)malloc(sizeof(nodetype));
	ptr -> next = (*top);
	ptr->info = num;

	(*top) = ptr;
}

void pop(nodetype **top)
{
	if(*top == NULL)	printf("stack underflow \n");
	else
	{
		printf("pop : %d\n",(*top)->info); (*top)= (*top)->next;
	}
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
	nodetype *head = NULL;

	for(int i=0; i<5; i++)
	{
		push(&head,i);
		display(head);
	}

	while(head)
	{
		pop(&head);
		display(head);
	}

	return 0;
}