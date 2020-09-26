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

map<int,int> mp;

void find_pairs(node *root,int sum)
{
	if(root==NULL) return;

	find_pairs(root->left,sum);

	int comp = sum-root->info;

	if(comp > root->info)
	{
		if(mp[comp]) cout<<root->info<<" "<<comp<<"\n";
	}

	find_pairs(root->right,sum);
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
			case 'i': int data; cin>>data; mp[data]=1;  insert(&root,data);   break;
			case 'f': cin>>key; cout<<mp[key]<<"\n"; 			  			  break;
			case 'p': cin>>sum; find_pairs(root,sum); cout<<"\n"; 		  	  break;
			default: exit(0);
		}
	}

	return 0;
}