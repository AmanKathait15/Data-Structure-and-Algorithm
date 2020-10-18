#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/check-whether-bst-contains-dead-end-not/

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
	else if((*root)->info<num)	insert(&((*root)->right), num);
	else						insert(&((*root)->left) , num);
}

void store_nodes(node *root,unordered_set<int> &all_nodes,unordered_set<int> &leaf_nodes)
{
	if(root==NULL) return ;

	all_nodes.insert(root->info);

	if(root->left==NULL and root->right==NULL) leaf_nodes.insert(root->info);

	store_nodes(root->left ,all_nodes,leaf_nodes);
	store_nodes(root->right,all_nodes,leaf_nodes);
}

bool check_deadEnd(node *root)
{
	unordered_set<int> all_nodes,leaf_nodes;

	all_nodes.insert(0);

	store_nodes(root,all_nodes,leaf_nodes);

	for(auto i=leaf_nodes.begin(); i!=leaf_nodes.end(); i++)
	{
		if(all_nodes.find(*i-1)!=all_nodes.end() and all_nodes.find(*i+1)!=all_nodes.end()) return 1;
	}

	return 0;
}

int main()
{
	node *root = NULL ,*lca = NULL; 

	while(1)
	{
		char ch; printf("i: insert d: check_deadEnd : ");
		cin>>ch; int m = 0,x,y;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);   break;
			case 'd': cout<<check_deadEnd(root)<<"\n";  		  break;

			default: exit(0);
		}
	}

	return 0;
}