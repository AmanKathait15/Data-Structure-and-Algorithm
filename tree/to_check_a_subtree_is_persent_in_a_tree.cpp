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
	else						insert(&((*root)->left) , num);
}

node* find_key(node *root,int key)
{
	if(root==NULL) return NULL;

	if(root->info==key) return root;
	else if(root->info>key) return find_key(root->left,key);
	else 					return find_key(root->right,key);
}

bool sub_tree(node *root,node *sub_root)
{
	if(root==NULL and sub_root==NULL) return 1;
	if(root==NULL or sub_root==NULL)  return 0;
	
	return (root->info == sub_root->info and sub_tree(root->left,sub_root->left) and sub_tree(root->right,sub_root->right)); 
}

bool check(node *root,node *sub_root)
{
	if(root==NULL) 	   return 0;
	if(sub_root==NULL) return 1;

	root = find_key(root,sub_root->info);

	if(root==NULL) return 0;

	return sub_tree(root,sub_root);
}

void levelOrderTraverser(node *root)
{
	if(root==NULL) return;

	int level = 1; 

	queue<pair<node*,int>> Queue;		// queue of pointers of node type

	Queue.push(make_pair(root,level));

	while(!Queue.empty())
	{
		root = Queue.front().first;

		if(Queue.front().second == level)	printf("\nlevel %d : ",level++);

		cout<<root->info<<" ";	

		Queue.pop();

		if(root->left)	Queue.push(make_pair(root->left,level));		// if left child is not null then push it on queue
		if(root->right)	Queue.push(make_pair(root->right,level));	// if right child is not null then push it on queue
	}
}

int main()
{
	node *root = NULL,*sub_root = NULL;

	while(1)
	{
		char ch; printf("\n i- insert parent tree\n I- insert sub tree\n c- check sub tree persent in a tree\n : ");

		cin>>ch; int data;

		system("clear");

		switch(ch)
		{
			case 'i': cin>>data;  insert(&root,data);		  	break;
			case 'I': cin>>data;  insert(&sub_root,data);   	break;
			case 'l': levelOrderTraverser(root);			 	break;
			case 'L': levelOrderTraverser(sub_root); 			break;
			
			case 'c': if(check(root,sub_root)) 
					  cout<<"sub_tree is persent in a tree\n";
					  else 	cout<<"sub_tree is not persent in a tree\n";
					  break;
			
			default: exit(0);
		}
	}

	return 0;
}