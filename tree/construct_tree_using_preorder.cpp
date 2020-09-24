#include<bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *left,*right;
};

node* create_node(int data)
{
    node *ptr = new node();

    ptr->info = data;

    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}

node* construct_tree(int arr[],int n,int *index)
{
    int i = *index;

    if(i == n) return NULL;

    node *ptr = create_node(arr[i]);

    (*index)++;

    vector<int> v1,v2;

    for(int j=i+1; j<n; j++)
    {
        if(arr[j]<arr[i]) v1.push_back(arr[j]);
        else              v2.push_back(arr[j]);
    }

    i=0;

    ptr->left = construct_tree(v1,v1.size(),i);
    ptr->right = construct_tree(v2,v2.size(),i);

    return ptr;
}

void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->info<<" ";
        inorder(root->right);
    }
}

int main()
{
    int n,i=0; cin>>n; node *root=NULL; vector<int> v(n);

    for(int i=0; i<n; i++) cin>>v[i];

    root = construct_tree(v,n,&i);

    inorder(root);

    return 0;
}