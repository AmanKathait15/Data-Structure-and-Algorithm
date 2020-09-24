#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	int prio;
	struct node *next;
} nodetype ;

void insert(nodetype ** , nodetype **);
void serve(nodetype** , nodetype **);
void display(nodetype*);

int main()
{
	nodetype *front = NULL, *rear=NULL; int ch;
	
	while(1)
	{
		printf("\nenter choice 1: insert 2: serve 3: display 4: exit\n");	scanf("%d",&ch);

		if(ch==1)	insert(&front,&rear);
		else if(ch==2)
		{
			if(front==NULL)	printf("\nunderflow");
			else		serve(&front,&rear);
		}
		else if(ch==3)
		{
			if(front==NULL)	printf("\nunderflow");
			else		display(front);
		}
		else if(ch==4)	break;
		else printf("\ninvalid choice");
	}
}

void insert(nodetype ** front , nodetype ** rear)
{
	nodetype *ptr; int num,p;

	printf("\nenter number and its priority ");
	scanf("%d%d",&num,&p);

	ptr = (nodetype*)malloc(sizeof(nodetype));
	ptr->info=num;
	ptr->prio=p;
	ptr->next=*front;

	if(*rear==NULL)
	*front=*rear=ptr;
	else
	{
		if(p<=(*front)->prio)
		*front=ptr;
		else if(p>(*rear)->prio)
		{
			(*rear)->next=ptr;	*rear=ptr;	ptr->next=NULL;
		}
		else
		{
			nodetype *tmp=*front;
			while(p>(tmp->next)->prio)
			tmp=tmp->next;
			ptr->next=tmp->next;
			tmp->next=ptr;
		}
	}	
}

void serve(nodetype ** front , nodetype **rear)
{
	nodetype *ptr=*front;

	printf("number serve is%d",ptr->info);
	*front=(*front)->next;

	free(ptr);
	if(*front==NULL)	*rear=NULL;
}

void display(nodetype *front)
{
	while(front!=NULL)
	{
		printf("\n%d",front->info);	front=front->next;
	}
}




