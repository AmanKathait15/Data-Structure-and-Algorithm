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

void find_pairs(node *root1,node *root2,int sum)
{
	if(root1==NULL || root2==NULL) return;

	if(root1->left)		find_pairs(root1->left,root2,sum);
	else if(root2->right)	find_pairs(root1,root2->right,sum);

	if(root1->info >= root2->info) 				return;
	else if((root1->info + root2->info) > sum )	find_pairs(root1,root2->left,sum);
	else if((root1->info + root2->info) < sum )	find_pairs(root1->right,root2,sum);
	else
	{
		cout<<root1->info<<" "<<root2->info<<"\n";

		if(root1->right)	find_pairs(root1->right,root2,sum);
		if(root2->left)		find_pairs(root1,root2->left,sum);
	}
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