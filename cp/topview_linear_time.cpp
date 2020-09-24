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

void topView(node *root , int n)
{
	queue<pair<node*,int>> Queue; int mp[n+n] , ind = n; memset(mp,-1,sizeof(mp));

	Queue.push(make_pair(root,ind));

	while(!Queue.empty())
	{
		root = Queue.front().first; ind = Queue.front().second; Queue.pop();

		if(mp[ind]==-1)	mp[ind] = root->info;

		if(root->left)	Queue.push(make_pair(root->left,ind-1));
		if(root->right)	Queue.push(make_pair(root->right,ind+1));

	}

	for(int i=0; i<(n+n); i++) if(mp[i]!=-1) cout<<mp[i]<<" ";
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

	topView(root,n);

	return 0;
}