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

node* Sort(node *head)
{
	node *zero=NULL,*one=NULL,*two=NULL,*zero_head=zero,*one_head=one,*two_head=two;

	while(head)
	{
		switch(head->info)
		{
			case 0: if(zero==NULL) zero_head=zero=head; else 	{zero->next=head; zero=zero->next} break;
			case 1: if(one==NULL) one_head=one=head; 	else	{one->next=head;} break;
			case 2: if(two==NULL) two_head=two=head; 	else 	{two->next=head;} break;
		}

		head=head->next;
	}

	zero->next = one_head; one->next= two_head;

	return zero_head;
}

int main()
{
	node *head = NULL , *tail = NULL;

	while(1)
	{
		char ch; printf("i,r,d,p,c,R,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); break;
			case 'r': pop(&head,&tail); break;
			case 'd': display(head); break;
			case 's': Sort(head); break;
			default: exit(0);
		}
	}

	return 0;
}