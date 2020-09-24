#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *left,*right;
};

bool check(int inorder[],int preorder[],int postorder[],int len)
{
	if(len==0) return 1;
	if(len==1) return (inorder[0]==preorder[0] and inorder[0]==postorder[0]); 
    //if(len==3) return (inorder[0]==postorder[0] and inorder[len-1]==preorder[len-1] and preorder[0]==postorder[len-1]);

	int ind = -1; for(int i=0; i<len; i++) if(inorder[i]==preorder[0]) { ind=i; break; }

	if(ind==-1) return 0; //cout<<ind<<"\n";

	bool lst = check(inorder,preorder+1,postorder,ind);
	bool rst = check(inorder+ind+1 ,preorder+ind+1 ,postorder+ind,len-ind-1);

	return (lst and rst);
}


int main()
{
    int n; cout<<"enter number of nodes in tree : "; cin>>n; 

    int inorder[n],preorder[n],postorder[n];

    cout<<"enter inorder traversal : "; 	for(int i=0; i<n; i++) cin>>inorder[i];
    cout<<"enter preorder traversal : "; 	for(int i=0; i<n; i++) cin>>preorder[i];
    cout<<"enter postorder traversal : "; 	for(int i=0; i<n; i++) cin>>postorder[i];

    if(check(inorder,preorder,postorder,n))	cout<<"\n all traverser are of same tree \n";
    else			cout<<"\n all traverser are not of same tree \n";

    return 0;
}