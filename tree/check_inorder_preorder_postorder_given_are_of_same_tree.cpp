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

	node *ptr = new node(); ptr->info = preorder[ind++];

	if(low==high) return ptr;

	int mid = mp[ptr->info]; // O(1)

	ptr->left  = construct_tree(preorder,inorder,low,mid-1);	// build LST
	ptr->right = construct_tree(preorder,inorder,mid+1,high);	// build RST

	return ptr;
}

void postorder_traverser(node *root,int postorder[],int &index)
{
	if(root)
	{
		postorder_traverser(root->left,postorder,index);
		postorder_traverser(root->right,postorder,index);
		
		if(root->info == postorder[index]) index++;
	}
}

int main()
{
    int n; cout<<"enter number of nodes in tree : "; cin>>n; 

    int inorder[n],preorder[n],postorder[n];

    cout<<"enter inorder traversal : "; 	for(int i=0; i<n; i++) { cin>>inorder[i]; mp[inorder[i]] = i; }
    cout<<"enter preorder traversal : "; 	for(int i=0; i<n; i++) cin>>preorder[i];
    cout<<"enter postorder traversal : "; 	for(int i=0; i<n; i++) cin>>postorder[i];

    node *root = construct_tree(preorder,inorder,0,n-1);

    int index=0; postorder_traverser(root,postorder,index);

    if(index==n)	cout<<"\n all traverser are of same tree \n";
    else			cout<<"\n all traverser are not of same tree \n";

    return 0;
}