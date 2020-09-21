#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int info;
	node *next;
};

node* push(node *top)
{
	int num; cout<<"enter a number : "; cin>>num;

	node *ptr = new node();

	ptr->info = num; ptr->next=top;

	return ptr;
}

node* pop(node *top)
{
	if(top == NULL)	printf("stack overflow \n");
	else
	{
		printf("%d \n",top->info); top=top->next;
	}
	return top;
}

void display(node *top)
{
	while(top)
	{
		printf("[%d]--",top->info); top=top->next;
	}	printf("NULL\n");
}

int main()
{
	node *top = NULL;

	while(1)
	{
		char ch; printf("i,r,d,e : ");
		cin>>ch;

		switch(ch)
		{
			case 'i': top = push(top); break;
			case 'r': top = pop(top); break;
			case 'd': display(top); break;
			default: exit(0);
		}
	}

	return 0;
}