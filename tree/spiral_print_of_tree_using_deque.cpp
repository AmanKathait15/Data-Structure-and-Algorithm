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

	deque<node*> d;

	d.push_back(root);

	while(!d.empty())
	{
		int size = d.size();

		while(size--)
		{
			node *tmp = d.back(); d.pop_back();

			cout<<tmp->info<<" ";

			if(tmp->left)  d.push_front(tmp->left);
			if(tmp->right) d.push_front(tmp->right);
		}

		size = d.size();

		while(size--)
		{
			node *tmp = d.front(); d.pop_front();

			cout<<tmp->info<<" ";

			if(tmp->right) d.push_back(tmp->right);
			if(tmp->left)  d.push_back(tmp->left);
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