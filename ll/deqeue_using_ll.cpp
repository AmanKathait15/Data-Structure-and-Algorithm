#include<bits/stdc++.h>
using namespace std;

int size = 0;

struct node 
{
	int info;
	node *next;
	node *prev;
};

void push_front(node **head, node **tail)
{
	int num; cout<<"enter a number : "; cin>>num; size++;

	node *ptr = new node();

	ptr->info = num; ptr->next=*head; ptr->prev = NULL;

	if(*head == NULL)	*tail=*head = ptr;
	else
	{
		(*head)->prev = ptr;
		*head = ptr;
	}
}

void push_back(node **head, node **tail)
{
	int num; cout<<"enter a number : "; cin>>num; size++;

	node *ptr = new node();

	ptr->info = num; ptr->next=NULL; ptr->prev = *tail;

	if(*head == NULL)	*head = *tail = ptr;
	else
	{
		(*tail)->next = ptr;
		*tail = ptr;
	}
}

void pop_front(node **head , node **tail)
{
	if(*head == NULL)	printf("empty \n");
	else
	{
		printf("%d \n",(*head)->info); 

		*head=(*head)->next; 
		
		if(*head)
			(*head)->prev = NULL; size--;
	}

	if(*head==NULL)	*tail = NULL;
}

void pop_back(node **head , node **tail)
{
	if(*tail == NULL)	printf("empty \n");
	else
	{
		printf("%d \n",(*tail)->info); 

		*tail=(*tail)->prev; 
		
		if(*tail)
			(*tail)->next = NULL; size--;
	}

	if(*tail==NULL)	*head = NULL;
}

void display(node *head)
{
	printf("NULL<-->");
	while(head)
	{
		printf("[%d]<-->",head->info); head=head->next;
	}	printf("NULL\n");
}

void reverse(node *tail)
{
	printf("NULL<-->");
	while(tail)
	{
		printf("[%d]<-->",tail->info); tail=tail->prev;
	}	printf("NULL\n");
}

int main()
{
	node *head = NULL , *tail = NULL;

	while(1)
	{
		char ch; printf("e,E,d,D,p,r,s,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'e': push_front(&head,&tail); break;
			case 'd': pop_front(&head,&tail); break;
			case 'E': push_back(&head,&tail); break;
			case 'D': pop_back(&head,&tail); break;
			case 'p': display(head); break;
			case 'r': reverse(tail); break;
			case 's': printf("size of deqeue is %d\n",size); break;
			default: exit(0);
		}
	}

	return 0;
}