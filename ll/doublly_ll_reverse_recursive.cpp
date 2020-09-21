#include<bits/stdc++.h>
using namespace std;

int size = 0;

struct node 
{
	int info;
	node *next;
	node *prev;
};

void push(node **head, node **tail)
{
	int num; cout<<"enter a number : "; cin>>num; size++;

	node *ptr = new node();

	ptr->info = num; ptr->next=NULL; ptr->prev = *tail;

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
		printf("%d \n",(*head)->info); 

		*head=(*head)->next; 
		
		if(*head)
			(*head)->prev = NULL; size--;
	}

	if(*head==NULL)	*tail = NULL;
}

node* reverse(node *curr)
{
	if(curr==NULL) return NULL;

	node *tmp = curr->next;
	curr->next = curr->prev;
	curr->prev = tmp;

	if(curr->prev==NULL) return curr;

	return reverse(curr->prev);
}

void display(node *head)
{
	while(head)
	{
		printf("[%d]<--->",head->info); head=head->next;
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
			case 'R': tail = head; head = reverse(head); break;
			default: exit(0);
		}
	}

	return 0;
}