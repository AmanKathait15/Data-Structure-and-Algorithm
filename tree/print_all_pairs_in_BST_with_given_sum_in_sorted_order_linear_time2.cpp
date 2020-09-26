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

void inorder(node *root,vector<int> &v)
{
	if(root)
	{
		inorder(root->left,v);
		v.push_back(root->info);
		inorder(root->right,v);
	}
}

void find_pairs(vector<int> &v,int sum)
{
	int l=0,h=v.size()-1;

	while(l<h)
	{
		if(v[l]+v[h]>sum) h--;
		else if(v[l]+v[h]<sum) l++;
		else
		{
			cout<<v[l]<<" "<<v[h]<<"\n"; l++; h--;
		}
	}
}

int main()
{
	node *root = NULL;

	while(1)
	{
		char ch; printf("i- insert p- print keys in given range : ");
		cin>>ch; int sum,key; vector<int> v;

		switch(ch)
		{
			case 'i': int data; cin>>data;   insert(&root,data);   	  			  break;
			case 'p': cin>>sum; inorder(root,v); find_pairs(v,sum); cout<<"\n";   break;
			default: exit(0);
		}
	}

	return 0;
}