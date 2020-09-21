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

void display(node *head)
{
	while(head)
	{
		printf("[%d]--",head->info); head=head->next;
	}	printf("NULL\n");
}

node* reverse(node* head) 
{ 
    if (head == NULL || head->next == NULL)  return head; 
  
    node* rest = reverse(head->next);

    head->next->next = head; 

    head->next = NULL;

    //display(head); display(rest); 
  
    return rest; 
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