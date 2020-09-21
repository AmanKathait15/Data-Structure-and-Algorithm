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

void segregate(node **head, node **tail)
{
	node *tmp = *head,*odd=NULL,*even=NULL,*beg,*end;

	while(tmp)
	{
		if((tmp->info)%2==0)
		{
			if(even==NULL) { beg = even = tmp; }
			else
			{
				even->next = tmp; even = even->next;
			}
		}
		else
		{
			if(odd==NULL) { end = odd = tmp; }
			else
			{
				odd->next = tmp; odd = odd->next;
			}
		}

		tmp = tmp->next;
	}

	if(even == NULL || odd == NULL) return ;

	even->next = end; odd->next = NULL;

	*head = beg; *tail = odd;
}

int main()
{
	node *head = NULL , *tail = NULL;

	while(1)
	{
		char ch; printf("i,r,d,s,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); break;
			case 'r': pop(&head,&tail); break;
			case 'd': display(head); break;
			case 's': segregate(&head,&tail); break;
			case 'l': printf("%d\n",size); break;
			default: exit(0);
		}
	}

	return 0;
}