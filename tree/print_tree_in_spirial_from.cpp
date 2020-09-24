#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int info;
	node *left;
	node *right;
};

void insert(node **root,int num)
{
	if((*root) == NULL)
	{
		*root = new node();
		(*root)->info = num;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else if((*root)->info<num)	insert(&((*root)->right) , num);
	else					insert(&((*root)->left) , num);
}

void spiral(node *root)
{
	if(root==NULL) return ;

	stack<node*> st1,st2;

	st1.push(root);

	while(!st1.empty() or !st2.empty())
	{
		while(!st1.empty())
		{
			node *tmp = st1.top(); st1.pop();

			cout<<tmp->info<<" ";

			if(tmp->left) st2.push(tmp->left);
			if(tmp->right) st2.push(tmp->right);
		}

		while(!st2.empty())
		{
			node *tmp = st2.top(); st2.pop();

			cout<<tmp->info<<" ";

			if(tmp->right) st1.push(tmp->right);
			if(tmp->left) st1.push(tmp->left);
		}
	}
}

int main()
{
	node *root = NULL;

	while(1)
	{
		char ch; printf("i-insert , s-spiral print : ");
		cin>>ch; int m = 0;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);  break;
			case 's': spiral(root); cout<<"\n";					 break;
			default: exit(0);
		}
	}

	return 0;
}