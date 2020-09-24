/* program to display bottom view of a tree 
ex - 			4
			2		6
		1	   3 5		7
							8
								9

o/p 1 2 5 6 7 8 9
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

void bottomView(node *root , int n)
{
	queue<pair<node*,int>> Queue; int mp[n+n]= {0}, ind = n;

	Queue.push(make_pair(root,ind));

	while(!Queue.empty())
	{
		root = Queue.front().first; ind = Queue.front().second; Queue.pop();

		mp[ind] = root->info;

		if(root->left)	Queue.push(make_pair(root->left,ind-1));
		if(root->right)	Queue.push(make_pair(root->right,ind+1));

	}

	for(int i=0; i<(n+n); i++) if(mp[i]!=0) cout<<mp[i]<<" ";
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

	bottomView(root,0);

	return 0;
}