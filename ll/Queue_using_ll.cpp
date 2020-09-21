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

void search(node *head, node *tail)
{
	if(head == NULL) return;

	printf("enter key to search : ");

	int key,c=0; cin>>key;

	if(head->info == key)	printf("found at %d\n",c);
	else if(tail->info == key) printf("found at %d\n",size-1);
	else
	{
		do
		{
			head = head->next; c++;
		}while(head && head->info != key);

		if(head)
		printf("found at %d\n",c);
	}

	printf("key not found\n");
}

void update(node **head,node **tail)
{
	if(*head == NULL) return;

	int c = 0,p,val; cout<<"enter position and new value to update : "; cin>>p>>val;

	if(p>=size) 	{ cout<<"out of bound \n"; return; }

	if(p==size-1)	(*tail)->info = val;
	else
	{
		node *tmp = *head;

		while(tmp && p--)
			tmp=tmp->next;

		tmp->info = val;
	}
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
		char ch; printf("i,r,d,e,l,s,u: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); break;
			case 'r': pop(&head,&tail); break;
			case 'd': display(head); break;
			case 'u': update(&head,&tail); break;
			case 's': search(head,tail); break;
			case 'l': printf("%d\n",size); break;
			default: exit(0);
		}
	}

	return 0;
}