#include<bits/stdc++.h>
using namespace std;
#define num int

struct trienode
{
	char data;
	num wordend;
	trienode * child[10];
};

trienode* insert(trienode *t,string str)
{
	num l = str.length();

	trienode *tmp = t;

	for(num i=0; i<l; i++)
	{
		if(t->child[str[i]-48]==NULL)
		{
			trienode *ptr = new trienode();
			ptr->data=str[i];
			if(i==l-1)
			ptr->wordend=1;
			t->child[str[i]-48]=ptr;
		}
		t = t->child[str[i]-48];
	}

	return tmp;
}

bool search(trienode *t, string str)
{
	num l = str.length();

	for(num i=0; i<l; i++)
	{
		if(t->child[str[i]-48]==NULL)
			return 0;

		t=t->child[str[i]-48];
		if(i==l-1 && t->wordend==0)
			return 0;
	}
	return 1;
}

void bfs(trienode *t)
{

	queue<trienode *> Queue;		// queue of ponumers of node type

	Queue.push(t);

	while(!Queue.empty())
	{
		trienode *root = Queue.front();

		cout<<root->data<<" ";

		for(num i=0; i<10; i++)
			if(root->child[i])
				Queue.push(root->child[i]);

		Queue.pop();
		cout<<"\n";
	}
}

int main()
{
	trienode *t = new trienode();

	num n;
	cin>>n;
	
	for(num i=0; i<=n; i++)
	{
		string str = to_string((num)pow(2,i));
		cout<<str<<" ";
		t = insert(t,str);
	}
	bfs(t);
	while(1)
	{
		string str;
		cin>>str;

		if(str=="end") break;

		cout<<search(t,str)<<"\n";
	}

	return 0;
}