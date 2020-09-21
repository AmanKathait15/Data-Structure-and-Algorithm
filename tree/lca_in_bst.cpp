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

void levelOrderTraverser(node *root)
{
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


void inorder(node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->info);
		inorder(root->right);
	}
}

bool find(node *root, int k)
{
	if(root == NULL) return 0;

	if(root->info == k) return 1;

	else if(k < root->info) return find(root->left,k);
	
	else 			   return find(root->right,k);
}

int LCA(node *root,int n1,int n2)
{
	if(root==NULL) return -1;

	if(root->info > n1 and root->info > n2)	return LCA(root->left,n1,n2);	//left subtree

	if(root->info < n1 and root->info < n2)	return LCA(root->right,n1,n2);	// right subtree

	return root->info;
}

int findLCA(node *root,int n1 , int n2)
{
	if(root == NULL) return -1;

	if(!find(root,n1) || !find(root,n2)) return -1;

	return LCA(root,n1,n2);
}

int main()
{
	node *root = NULL ,*lca = NULL; 

	while(1)
	{
		char ch; printf("i,d,L,l,r,e: ");
		cin>>ch; int m = 0,x,y;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);  		  break;
			case 'I': inorder(root); 				cout<<"\n";  		  break;
			case 'L': levelOrderTraverser(root);	cout<<"\n";  		  break;
			case 'l': cout<<"enter two values : "; cin>>x>>y; cout<<findLCA(root,x,y)<<"\n";  break;

			default: exit(0);
		}
	}

	return 0;
}