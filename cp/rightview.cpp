/* program to display right view of a tree 
ex - 			4
			2		6
		1	   3 5		7
							8
								9

o/p 	4 6 7 8 9
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
	node *left = NULL;
	int info;
	node *right = NULL;	
};

void insert(node **root, int key)
{
	if((*root) == NULL)		// base case
	{
		(*root) = new node();
		(*root)->info = key;
		(*root)->left = (*root)->right = NULL;
	}
	else if(key > (*root)->info)
	{
		insert(&((*root)->right),key);
	}											// imagination
	else
	{
		insert(&((*root)->left),key);
	}
}

void rightView(node *root , int level)
{
	queue<pair<node*,int>> Queue;		// queue of pointers of node type

	Queue.push(make_pair(root,level));

	while(!Queue.empty())
	{
		root = Queue.front().first;

		if(Queue.front().second == level && level++)	cout<<root->info<<" ";	
		Queue.pop();

		if(root->right)	Queue.push(make_pair(root->right,level));	// if right child is not null then push it on queue
		if(root->left)	Queue.push(make_pair(root->left,level));		// if left child is not null then push it on queue

	}
}

void inorder(node *root)
{
	if(root == NULL)	return;		//base case

	inorder(root->left);
	printf("%d ",root->info);
	inorder(root->right);
}

int main()
{
	int n; node *root = NULL;
	cin>>n;

	while(1)
	{
		int num;
		cin>>num;

		if(num == n)	break;

		insert(&root,num);
	}

	//inorder(root);

	rightView(root,1);

	return 0;
}