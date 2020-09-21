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


void leftView(node *root,int level,int* maxlevel)
{
	if(root)
	{
		if(level > (*maxlevel))
		{
			cout<<root->info<<" "; *maxlevel = level;
		}

		leftView(root->left,level+1,maxlevel);
		leftView(root->right,level+1,maxlevel);
	}
}

void rightView(node *root,int level,int *maxlevel)
{
	if(root)
	{
		if(level > (*maxlevel))
		{
			cout<<root->info<<" "; *maxlevel = level;
		}

		rightView(root->right,level+1,maxlevel);
		rightView(root->left,level+1,maxlevel);
	}
}

void topView(node *root)
{
	queue<pair<node*,int>> q; map<int,int> mp; int ind=0;

	q.push({root,ind});

	while(!q.empty())
	{
		root = q.front().first; int ind = q.front().second; q.pop();

		mp.insert({ind,root->info});

		if(root->left)  q.push({root->left,ind-1});
		if(root->right) q.push({root->right,ind+1});
	}

	for(auto i=mp.begin(); i!=mp.end(); i++)	cout<<i->second<<" ";
}

void bottomView(node *root)
{
	queue<pair<node*,int>> q; map<int,int> mp; int ind=0;

	q.push({root,ind});

	while(!q.empty())
	{
		root = q.front().first; int ind = q.front().second; q.pop();

		mp[ind] = root->info;

		if(root->left)  q.push({root->left,ind-1});
		if(root->right) q.push({root->right,ind+1});
	}

	for(auto i=mp.begin(); i!=mp.end(); i++)	cout<<i->second<<" ";
}

bool isBST(node *root,int min, int max)
{
	if(root==NULL) return 1;

	if(root->info < min || root->info > max) return 0;

	return (isBST(root->left,min,root->info-1) and isBST(root->right,root->info+1,max));
}

bool isbst(node *root, node *prev)		// inorer approach
{
	if(root)
	{
		if(!isbst(root->left,prev)) return 0;

		if(prev!=NULL and prev->info >= root->info) return 0;

		prev = root;

		return isbst(root->right,prev); 
	}

	return 1;
}

int sumTree(node *root)
{
	if(root==NULL) return 0;

	int old_val = root->info;

	root->info = sumTree(root->left) + sumTree(root->right);

	return root->info + old_val;
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

void preorder(node *root)
{
	if(root)
	{
		printf("%d ",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->info);
	}
}

int main()
{
	node *root = NULL;

	while(1)
	{
		char ch; printf("i,d,I,p,P,L,l,r,t,b,c,C,s,e: ");
		cin>>ch; int m = 0;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);  break;
			case 'I': inorder(root); 				cout<<"\n";  break;
			case 'p': preorder(root); 				cout<<"\n";  break;
			case 'P': postorder(root); 				cout<<"\n";  break;
			case 'l': leftView(root,1,&m); 			cout<<"\n";  break;
			case 'r': rightView(root,1,&m);	 		cout<<"\n";  break;
			case 't': topView(root);		 		cout<<"\n";  break;
			case 'b': bottomView(root);			 	cout<<"\n";  break;
			case 'c': cout<<isBST(root,INT_MIN,INT_MAX)<<"\n";   break;
			case 'C': cout<<isbst(root,NULL)<<"\n";   			 break;
			case 's': cout<<sumTree(root)<<"\n";	   			 break;
			case 'L': levelOrderTraverser(root);	cout<<"\n";  break;
			default: exit(0);
		}
	}

	return 0;
}