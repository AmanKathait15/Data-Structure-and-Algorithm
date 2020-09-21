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

	ptr->info = num; ptr->next=*head;

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
	if(*head == *tail)
	{
		*head = *tail = NULL; return;
	}
	else
	{
		printf("%d \n",(*head)->info); *head=(*head)->next;	(*tail)->next = *head; size--;
	}
}

void display(node *head)
{
	if(head==NULL) return;

	node *tmp = head;

	do
	{
		printf("[%d]--",head->info); 
		head=head->next;

	}while(head!=tmp);

	printf("--loop\n");
}

int isloop(node *head)
{
	map<node*,int> mp; int c=1;

	while(head)
	{
		if(mp[head]) return  (c - mp[head]);
		else	mp[head] = c; c++;
		head = head->next;
	}

	return 0;
}

void split(node *head)
{
	if(head == NULL || head->next == NULL)	return;

	node *slow = head,*fast = head->next, *ll1=slow,*ll2;

	while(fast->next!=head && (fast->next)->next != head)
	{
		slow = slow->next;
		fast = (fast->next)->next;
	}

	if((fast->next)->next == head)
	{
		fast = fast -> next; slow = slow -> next;
	}

	ll2 = slow->next; fast->next = ll2; slow->next=ll1;

	display(ll1);
	display(ll2);

	if(isloop(ll1)) cout<<"loop found of length "<<isloop(ll1)<<"\n"; else cout<<"no loop exist\n";
	if(isloop(ll2)) cout<<"loop found of length "<<isloop(ll2)<<"\n"; else cout<<"no loop exist\n";
}

int main()
{
	node *head = NULL , *tail = NULL,*head2 = NULL , *tail2 = NULL;

	while(1)
	{
		char ch; printf("i,r,d,s,l,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); break;
			case 'r': pop(&head,&tail); break;
			case 'd': display(head); break;
			case 's': split(head); break;
			case 'l': if(isloop(head)) cout<<"loop found of length "<<isloop(head)<<"\n"; else cout<<"no loop exist\n"; break;
			default: exit(0);
		}
	}

	return 0;
}