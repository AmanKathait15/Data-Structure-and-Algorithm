#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *left,*right;
};

map<int,int> mp;

bool check(int inorder[],int preorder[],int postorder[],int len)
{
	if(len==0) return 1;
	if(len==1) return (inorder[0]==preorder[0] and inorder[0]==postorder[0]);

	if(mp[preorder[0]]==0) return 0;

	int ind = mp[preorder[0]]; ind = ind%len;

	bool lst = check(inorder,preorder+1,postorder,ind);
	bool rst = check(inorder+ind+1 ,preorder+ind+1 ,postorder+ind,len-ind-1);

	return (lst and rst);
}


int main()
{
    int n; cout<<"enter number of nodes in tree : "; cin>>n; 

    int inorder[n],preorder[n],postorder[n];

    cout<<"enter inorder traversal : "; 	for(int i=0; i<n; i++) { cin>>inorder[i]; mp[inorder[i]] = i; }
    cout<<"enter preorder traversal : "; 	for(int i=0; i<n; i++) cin>>preorder[i];
    cout<<"enter postorder traversal : "; 	for(int i=0; i<n; i++) cin>>postorder[i];

    if(check(inorder,preorder,postorder,n))	cout<<"\n all traverser are of same tree \n";
    else			cout<<"\n all traverser are not of same tree \n";

    return 0;
}