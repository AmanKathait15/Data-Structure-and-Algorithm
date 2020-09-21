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

bool findPath(node *root,vector<int> &path, int k)
{
	if(root==NULL) return 0;

	path.push_back(root->info);

	if(root->info == k) return 1;

	if(!(root->left and findPath(root->left,path,k))) 	return 1;	//found in left sub tree

	if(!(root->right and findPath(root->right,path,k))) return 1;	//found in right sub tree

	path.pop_back();

	return 0;
}

int findLCA(node *root,int n1,int n2)
{
	vector<int> path1,path2;

	if(!findPath(root,path1,n1) or !findPath(root,path2,n2)) return -1;

	for(int i=0; i<path1.size(); i++) cout<<path1[i]<<" ";		
	for(int i=0; i<path2.size(); i++) cout<<path2[i]<<" ";

	int i=0; for(; i<path1.size() && i<path2.size(); i++) if(path1[i]!=path2[i]) break;

	return path1[i-1];
}

node* LCA(node *root,int n1,int n2)
{
	if(root==NULL) return NULL;

	if(root->info == n1 || root->info == n2) return root;

	node *llca = LCA(root->left,n1,n2);
	node *rlca = LCA(root->right,n1,n2);

	if(llca and rlca) return root;

	return (llca)?llca:rlca;
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
			case 'l': cout<<"enter two values : "; cin>>x>>y;
			 		  cout<<findLCA(root,x,y)<<"\n";  
			 		  break;
			case 'r': cout<<"enter two values : "; cin>>x>>y; 
					  lca = LCA(root,x,y);   if(lca) cout<<lca->info<<"\n";  		  
					  break;

			default: exit(0);
		}
	}

	return 0;
}