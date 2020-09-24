#include<bits/stdc++.h>
using namespace std;

int size = 0;

struct node 
{
	int info;
	node *next;
};

void push(node **head, node **tail)
{
	int num; cout<<"enter a number : "; cin>>num; size++;

	node *ptr = new node();

	ptr->info = num; ptr->next=NULL;

	if(*head == NULL)
	{
		*head = *tail = ptr;
	}
	else
	{
		(*tail)->next = ptr;
		*tail = (*tail)->next;
	}
}

void pop(node **head , node **tail)
{
	if(*head == NULL)	printf("empty \n");
	else
	{
		printf("%d \n",(*head)->info); *head=(*head)->next; size--;
	}

	if(*head==NULL)	*tail = NULL;
}


void display(node *head)
{
	while(head)
	{
		printf("[%d]--",head->info); head=head->next;
	}	printf("NULL\n");
}

void split(node *head,node **ll1, node **ll2)
{
	node *tmp = head->next;

	while(tmp!=NULL && tmp->next!=NULL)
	{
		head = head->next; tmp=(tmp->next)->next;
	}

	(*ll2) = head->next; head->next = NULL;
}

node * merge(node *ll1, node *ll2)
{
	node *res = NULL;

	if(ll1==NULL)	return ll2;
	if(ll2==NULL) 	return ll1;

	if(ll1->info < ll2->info)
	{
		res = ll1; res->next = merge(ll1->next,ll2);
	}
	else
	{
		res = ll2; res->next = merge(ll1,ll2->next);
	}

	return res;
}

void mergesort(node **head)
{
	node *ll1 = *head,*ll2;

	if(*head==NULL || (*head)->next == NULL) 	return ;

	split(*head,&ll1,&ll2);

	mergesort(&ll1);
	mergesort(&ll2);
	
	*head = merge(ll1,ll2);
}

int main()
{
	node *head = NULL , *tail = NULL;

	while(1)
	{
		char ch; printf("i,r,d,m,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); break;
			case 'r': pop(&head,&tail); break;
			case 'd': display(head); break;
			case 'm': mergesort(&head);	while(tail->next)	tail=tail->next; break;
			default: exit(0);
		}
	}

	return 0;
}