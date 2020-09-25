#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *left,*right;
};

map<int,int> mp; // map used to store (value , index) of inorder traverser

node* construct_tree(int preorder[],int inorder[],int low,int high)
{
	static int ind = 0;	//value not change during recursive call u can use extra paramter for ind in place of static

	if(low>high) return NULL;

	node *ptr = new node(); ptr->info = preorder[ind]; ind++;

	if(low==high) return ptr;

	int mid = mp[ptr->info]; // O(1)

	ptr->left  = construct_tree(preorder,inorder,low,mid-1);	// build LST
	ptr->right = construct_tree(preorder,inorder,mid+1,high);	// build RST

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

void one_child(node *root)
{
	if(root)
	{
		if(root->left and root->right)
		{
			one_child(root->left);
			one_child(root->right);
		}
		else if(root->left)
		{
			cout<<root->info<<" "; one_child(root->left);
		}
		else
		{
			cout<<root->info<<" "; one_child(root->right);
		}
	}
}

int main()
{
    int n; cout<<"enter number of nodes in tree : "; cin>>n; 

    int inorder[n],preorder[n]; 

    cout<<"enter inorder traversal : "; 	for(int i=0; i<n; i++) { cin>>inorder[i]; mp[inorder[i]] = i; }
    cout<<"enter preorder traversal : "; 	for(int i=0; i<n; i++) cin>>preorder[i];

    node *root = construct_tree(preorder,inorder,0,n-1);

    cout<<"\none child nodes   : "; one_child(root);
    cout<<"\ninorder_traverser : "; inorder_traverser(root);

    return 0;
}