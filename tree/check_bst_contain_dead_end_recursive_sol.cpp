#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/simple-recursive-solution-check-whether-bst-contains-dead-end/

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

bool check_deadEnd(node *root,int min,int max)
{
	if(root==NULL) return 0;

	if(min==max)   return 1;

	return (check_deadEnd(root->left,min,root->info-1) or check_deadEnd(root->right,root->info+1,max));
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
			case 'i': int data; cin>>data;  insert(&root,data);  		  break;
			case 'd': cout<<check_deadEnd(root,1,INT_MAX)<<"\n";  		  break;

			default: exit(0);
		}
	}

	return 0;
}