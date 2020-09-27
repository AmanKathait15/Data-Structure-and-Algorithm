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

bool find_key(node *root,int key)
{
	if(root==NULL) return 0;

	if(key==root->info) return 1;
	else if(key<root->info) return find_key(root->left,key);
	else 					return find_key(root->right,key);
}

void find_pairs(node *root1,node *root2,int sum)
{
	stack<node*> s1,s2; bool flag1=1,flag2=1; int val1,val2;

	while(1)
	{
		while(flag1)
		{
			if(root1!=NULL)
			{
				s1.push(root1); root1=root1->left;
			}
			else if(s1.empty())	flag1=0;
			else
			{
				root1 = s1.top(); s1.pop(); val1=root1->info; root1=root1->right; flag1=0;
			}
		}

		while(flag2)
		{
			if(root2!=NULL)
			{
				s2.push(root2); root2=root2->right;
			}
			else if(s2.empty())	flag2=0;
			else
			{
				root2 = s2.top(); s2.pop(); val2=root2->info; root2=root2->left; flag2=0;
			}
		}

		if(val1>=val2) 				break;
		else if(val1+val2 == sum)
		{
			cout<<val1<<" "<<val2<<"\n"; flag1=flag1=1;
		}
		else if(val1+val2 < sum) 	flag1=1;
		else 					 	flag2=1;
	}
}

int main()
{
	node *root = NULL;

	while(1)
	{
		char ch; printf("i- insert p- print keys in given range : ");
		cin>>ch; int sum,key;

		switch(ch)
		{
			case 'i': int data; cin>>data;  insert(&root,data);   break;
			case 'f': cin>>key; cout<<find_key(root,key)<<"\n";   break;
			case 'p': cin>>sum; find_pairs(root,root,sum); cout<<"\n"; break;
			default: exit(0);
		}
	}

	return 0;
}