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

int maxPathsum(node *root, int &res)
{
	if(root==NULL) return 0;

	int lst = maxPathsum(root->left,res);
	int rst = maxPathsum(root->right,res);

	int ms = max(max(lst,rst)+root->info , root->info);	// find max among cuur node , curr node + lst , curr node + rst

	int mt = max(ms, lst+rst + root->info);	// find max among prev res and curr node + rst + lst

	res = max(res,mt);	// update res if greater

	return ms;	// return ms not mt because mt may contain both lst and rst to parent which is wrong
}

int main()
{
	node *root = NULL ,*lca = NULL; 

	while(1)
	{
		char ch; printf("i,d,L,l,r,e: ");
		cin>>ch; int data,res=INT_MIN;

		switch(ch)
		{
			case 'i': data; cin>>data;  insert(&root,data);  break;
			case 's': maxPathsum(root,res); cout<<res<<"\n"; break;

			default: exit(0);
		}
	}

	return 0;
}