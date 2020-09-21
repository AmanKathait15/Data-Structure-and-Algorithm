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

bool burn(node *root , queue<node*> &Q, int start , int *time)
{
	if(root==NULL) return 0;

	if(root->info == start)
	{
		cout<<start<<"\n";

		if(root->left)  Q.push(root->left);
		if(root->right) Q.push(root->right);

		return 1; 
	}

	bool lst = burn(root->left,Q,start,time);

	if(lst)
	{
		int size = Q.size();

		while(size--)
		{
			node *ptr = Q.front(); Q.pop();

			cout<<ptr->info<<" ";

			if(ptr->left)  Q.push(ptr->left);
			if(ptr->right) Q.push(ptr->right); 
		}

		cout<<root->info<<"\n"; (*time)++;

		if(root->right) Q.push(root->right);

		return 1;
	}

	bool rst = burn(root->right,Q,start,time);

	if(rst)
	{
		int size = Q.size();

		while(size--)
		{
			node *ptr = Q.front(); Q.pop();

			cout<<ptr->info<<" ";

			if(ptr->left)  Q.push(ptr->left);
			if(ptr->right) Q.push(ptr->right); 
		}

		cout<<root->info<<"\n"; (*time)++;

		if(root->left) Q.push(root->left);

		return 1;
	}

	return 0;
}

int burnTree(node *root,int start)
{
	if(root==NULL) return -1;	queue<node*> Q; int time=0;

	burn(root,Q,start,&time);

	while(!Q.empty())
	{
		int size = Q.size();

		while(size--)
		{
			node *ptr = Q.front(); Q.pop();

			cout<<ptr->info<<" ";

			if(ptr->left)  Q.push(ptr->left);
			if(ptr->right) Q.push(ptr->right); 
		}

		cout<<"\n"; time++;
	}

	return time;
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
			case 'L': levelOrderTraverser(root);	cout<<"\n";  		  break;

			case 'B': cout<<"enter start node : "; cin>>x; cout<<burnTree(root,x)<<"\n";  	  break;

			default: exit(0);
		}
	}

	return 0;
}