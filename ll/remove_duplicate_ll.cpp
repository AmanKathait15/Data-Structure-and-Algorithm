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

void remove_duplicate(node **head,node **tail)
{
	if(*head==NULL) return ;

	map<int,int> mp; 
	node *prev,*tmp = *head;

	while(tmp)
	{
		if(mp[tmp->info] && tmp == *tail)
		{
			prev->next = tmp->next; *tail = prev;
		}
		else if(mp[tmp->info])	prev->next = tmp->next;
		else
		{
			mp[tmp->info]=1;
			prev = tmp;
		}

		tmp = tmp->next;
	}
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
			case 'R': remove_duplicate(&head,&tail); break;
			case 'l': printf("%d\n",size); break;
			default: exit(0);
		}
	}

	return 0;
}