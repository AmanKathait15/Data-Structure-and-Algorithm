/* program to display right view of a tree 
ex - 			4
			2		6
		1	   3 5		7
							8
								9

o/p 1 2 4 6 7 8 9
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
	node *left = NULL;
	int info;
	int dist; 					// horizontal distance
	node *right = NULL;	
};

void insert(node **root, int key , int count)
{
	if((*root) == NULL)		// base case
	{
		(*root) = new node();
		(*root)->info = key;
		(*root)->dist = count;
		(*root)->left = (*root)->right = NULL;
	}
	else if(key > (*root)->info)
	{
		insert(&((*root)->right),key,count+1);
	}											// imagination
	else
	{
		insert(&((*root)->left),key,count-1);
	}
}

void topView(node *root , int dist)
{
	queue<pair<node*,int>> Queue;		// queue of pointers of node type
	map<int,int> Map;

	Queue.push(make_pair(root,dist));

	while(!Queue.empty())
	{
		root = Queue.front().first; dist = Queue.front().second;

		Map.insert({dist,root->info});
	
		Queue.pop();

		if(root->right)	Queue.push(make_pair(root->right,dist+1));	// if right child is not null then push it on queue
		if(root->left)	Queue.push(make_pair(root->left,dist-1));		// if left child is not null then push it on queue

	}

	for (auto i = Map.begin(); i!= Map.end(); ++i)
	{
		cout<<(*i).second<<" ";
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

		insert(&root,num,0);
	}
	return 0;
}