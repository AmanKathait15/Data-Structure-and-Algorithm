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

node* reverse(node *head)
{
	node *tmp = head;	stack<int> st;

	while(tmp)
	{
		st.push(tmp->info); tmp=tmp->next;
	}

	tmp = head;

	while(!st.empty())
	{
		tmp->info = st.top();	tmp=tmp->next;  st.pop();
	}

	return head;
}

bool is_palindrome(node *head)
{
	node *slow,*fast; slow=fast=head;

	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow -> next;
		fast=(fast->next)->next;
	}

	if(fast!=NULL) slow=slow->next;

	stack<int> st;

	while(slow!=NULL)
	{
		st.push(slow->info);	slow = slow->next;
	}

	while(!st.empty())
	{
		if(head->info!= st.top()) return 0;

		head=head->next; st.pop();
	}

	return 1;
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
			case 'c': head=NULL; break;
			case 'R': head = reverse(head); break;
			case 'p': if(is_palindrome(head))	printf("palindrome\n");	else cout<<"not palindrome\n"; break;
			default: exit(0);
		}
	}

	return 0;
}