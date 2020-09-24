#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *left,*right;
};

map<int,int> mp; // map used to store (value , index) of inorder traverser

node* construct_tree(int postorder[],int inorder[],int low,int high)
{
	static int ind = high;	//value not change during recursive call u can use extra paramter for ind in place of static

	if(low>high) return NULL;

	node *ptr = new node(); ptr->info = postorder[ind--];

	if(low==high) return ptr;

	int mid = mp[ptr->info]; // O(1)

	ptr->right  = construct_tree(postorder,inorder,mid+1,high);	// build RST
	ptr->left = construct_tree(postorder,inorder,low,mid-1);	// build LST

	return ptr;
}

void inorder_traverser(node *root)
{
    if(root)
    {
        inorder_traverser(root->left);	
        cout<<root->info<<" ";
        inorder_traverser(root->right);
    }
}

void preorder_traverser(node *root)
{
	if(root)
	{
		printf("%d ",root->info);
		preorder_traverser(root->left);
		preorder_traverser(root->right);
	}
}

void postorder_traverser(node *root)
{
	if(root)
	{
		postorder_traverser(root->left);
		postorder_traverser(root->right);
		printf("%d ",root->info);
	}
}

void levelOrderTraverser(node *root)
{
	int level = 1; 

	queue<pair<node*,int>> Queue;		// queue of pointers of node type

	Queue.push(make_pair(root,level));

	while(!Queue.empty())
	{
		root = Queue.front().first;

		if(Queue.front().second == level)	printf("\n level %d : ",level++);

		cout<<root->info<<" ";	

		Queue.pop();

		if(root->left)	Queue.push(make_pair(root->left,level));		// if left child is not null then push it on queue
		if(root->right)	Queue.push(make_pair(root->right,level));	// if right child is not null then push it on queue
	}
}


void leftView(node *root)
{
	int level = 1; 

	queue<pair<node*,int>> Queue;		// queue of pointers of node type

	Queue.push(make_pair(root,level));

	while(!Queue.empty())
	{
		root = Queue.front().first;

		if(Queue.front().second == level) { cout<<root->info<<" "; level++; }	

		Queue.pop();

		if(root->left)	Queue.push(make_pair(root->left,level));	// if left child is not null then push it on queue
		if(root->right)	Queue.push(make_pair(root->right,level));	// if right child is not null then push it on queue
	}
}

void rightView(node *root)
{
	int level = 1; 

	queue<pair<node*,int>> Queue;		// queue of pointers of node type

	Queue.push(make_pair(root,level));

	while(!Queue.empty())
	{
		root = Queue.front().first;

		if(Queue.front().second == level) { cout<<root->info<<" "; level++; }

		Queue.pop();

		if(root->right)	Queue.push(make_pair(root->right,level));	// if right child is not null then push it on queue
		if(root->left)	Queue.push(make_pair(root->left,level));	// if left child is not null then push it on queue
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

int main()
{
    int n; cout<<"enter number of nodes in tree : "; cin>>n; 

    int inorder[n],postorder[n]; 

    cout<<"enter inorder traversal : "; 	for(int i=0; i<n; i++) { cin>>inorder[i]; mp[inorder[i]] = i; }
    cout<<"enter preorder traversal : "; 	for(int i=0; i<n; i++) cin>>postorder[i];

    node *root = construct_tree(postorder,inorder,0,n-1);

    cout<<"\n inorder_traverser   : ";			inorder_traverser(root);
    cout<<"\n preorder traverer   : ";			preorder_traverser(root);
    cout<<"\n postorder_traverser : ";			postorder_traverser(root);
    cout<<"\n levelOrderTraverser : ";			levelOrderTraverser(root);
    cout<<"\n leftView of tree    : ";			leftView(root);
    cout<<"\n rightView  of tree  : ";			rightView(root);
    cout<<"\n topView of tree     : ";			topView(root);
    cout<<"\n bottomView of tree  : ";			bottomView(root);
    cout<<"\n tree is bst or not ?: ";			cout<<isBST(root,INT_MIN,INT_MAX)<<"\n";

    return 0;
}