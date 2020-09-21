#include<bits/stdc++.h>
using namespace std;

int size = 0;

struct node 
{
	int info;
	node *next;
};

void push2(node **head, node **tail)
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

void pop2(node **head , node **tail)
{
	if(*head == NULL)	printf("empty \n");
	else
	{
		printf("%d \n",(*head)->info); *head=(*head)->next; size--;
	}

	if(*head==NULL)	*tail = NULL;
}

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
	if(*head == NULL)	return;
	else
	{
		printf("%d \n",(*head)->info); *head=(*head)->next; size--;
	}

	if(*head==(*tail)->next)
	{
		*head = NULL; *tail = NULL;
	}
}


void display(node *head,node *tail)
{
	if(head==NULL) return;

	do
	{
		printf("[%d]--",head->info); 
		head=head->next;

	}while(head!=tail->next);

	printf("--loop\n");
}

int looplength(node *start)
{
	node *end = start->next;

	int c=1;

	while(start != end)
	{
		end = end->next; c++;
	}

	return c;
}

int isloop(node *slow)
{
	node *fast = slow->next;

	while(fast && fast->next!=NULL)
	{
		slow = slow->next;
		fast = (fast->next)->next;

		if(fast == slow)
			return looplength(slow);
	}

	return 0;
}

int isloop2(node *head)
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

int main()
{
	node *head = NULL , *tail = NULL,*head2 = NULL , *tail2 = NULL;

	while(1)
	{
		char ch; printf("i,r,d,m,e: ");
		cin>>ch;

		switch(ch)
		{
			case 'i': push(&head,&tail); push2(&head2,&tail2); break;
			case 'r': pop(&head,&tail); pop2(&head2,&tail2); break;
			case 'd': display(head,tail); break;
			case 'l': if(isloop(head)) cout<<"loop found of length "<<isloop(head)<<"\n"; else cout<<"no loop exist\n";
			if(isloop(head2)) cout<<"loop found of length "<<isloop(head2)<<"\n"; else cout<<"no loop exist\n";  break;
			case 'L': if(isloop2(head)) cout<<"loop found of length "<<isloop2(head)<<"\n"; else cout<<"no loop exist\n";
			if(isloop2(head2)) cout<<"loop found of length "<<isloop2(head2)<<"\n"; else cout<<"no loop exist\n";  break;
			default: exit(0);
		}
	}

	return 0;
}