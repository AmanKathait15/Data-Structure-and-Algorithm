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

bool find_key(node *root,int key)
{
	if(root==NULL) return 0;

	if(key==root->info) return 1;
	else if(key<root->info) return find_key(root->left,key);
	else 					return find_key(root->right,key);
}

void find_pairs(node *start,node *root,int sum)
{
	if(root==NULL) return;

	find_pairs(start,root->left,sum);

	int comp = sum-root->info;

	if(comp > root->info)
	{
		if(find_key(start,comp)) cout<<root->info<<" "<<comp<<"\n";
	}

	find_pairs(start,root->right,sum);
}

int main()
{
	node *root = NULL;

	while(1)
	{
		char ch; printf("i- insert p- print keys in given range : ");
		cin>>ch; int sum,key;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);   break;
			case 'f': cin>>key; cout<<find_key(root,key)<<"\n";   break;
			case 'p': cin>>sum; find_pairs(root,root,sum); cout<<"\n"; break;
			default: exit(0);
		}
	}

	return 0;
}