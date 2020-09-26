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

void keys_in_range(node *root,int l,int h)
{
	if(root)
	{
		if(root->info < l) 		keys_in_range(root->right,l,h);
		else if(root->info > h) keys_in_range(root->left,l,h);
		else
		{
			keys_in_range(root->left,l,h);
			cout<<root->info<<" ";
			keys_in_range(root->right,l,h);
		}
	}
}

void keys_in_range2(node *root,int l,int h)
{
	if(root)
	{
		if(l<root->info) keys_in_range2(root->left,l,h);
		if(l<=root->info and h>=root->info) cout<<root->info<<" ";
		if(h>root->info) keys_in_range2(root->right,l,h);
	}
}

int main()
{
	node *root = NULL;

	while(1)
	{
		char ch; printf("i- insert p- print keys in given range : ");
		cin>>ch; int l,h;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);  break;
			case 'p': cin>>l>>h; keys_in_range2(root,l,h);        break;
			default: exit(0);
		}
	}

	return 0;
}