#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int info;
	node *next;
};

void push(node **head, node **tail)
{
	int num; cout<<"enter a number : "; cin>>num;

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
		printf("%d \n",(*head)->info); *head=(*head)->next;
	}

	if(*head==NULL)	*tail = NULL;
}

void reverse(node **head , node **tail)
{
	node *curr=*head, *Next = *head, *prev=NULL; *tail = *head;

	while(curr)
	{
		Next = curr -> next;
		curr->next = prev; // first case m NULL
		prev = curr;
		curr = Next;
	}

	*head = prev;
}

void display(node *head)
{
	while(head)
	{
		printf("[%d]--",head->info); head=head->next;
	}	printf("NULL\n");
}

int main()
{
	node *head = NULL , *tail = NULL;

	while(1)
	{
		char ch; printf("i,r,d,R,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); break;
			case 'r': pop(&head,&tail); break;
			case 'd': display(head); break;
			case 'R': reverse(&head,&tail); break;
			default: exit(0);
		}
	}

	return 0;
}