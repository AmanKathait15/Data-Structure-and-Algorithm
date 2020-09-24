#include<bits/stdc++.h>
using namespace std;

struct trie
{
	bool isEndofword;

	map<char,trie*> mp;
};


void insert(trie *root,string str)
{
	int l = str.length();

	for(int i=0; i<l; i++)
	{
		char ch = str[i];

		if(!(root->mp[ch]))
		{
			trie *ptr = new trie;
			root->mp[ch] = ptr;
			root = root->mp[ch];
		}
		else root = root->mp[ch];

		if(i==l-1)	root->isEndofword = 1;
	}
}

bool search(trie *root,string str,bool flag)
{
	int l = str.length();

	for(int i=0; i<l; i++)
	{
		char ch = str[i];

		if(!(root->mp[ch]))	return false;
		else root = root->mp[ch];

		if(i==l-1 && root->isEndofword==0) return false;
	}

	if(flag)	root->isEndofword = 0;

	return true;
}

void display(trie *root,string str)
{
	for(auto i=(root->mp).begin(); i!=(root->mp).end(); i++)
	{
		if((i->second)->isEndofword)
			cout<<str+(i->first)<<"\n";

		display(i->second,str+(i->first));
	}
}

int main()
{
	trie root;

	while(1)
	{
		char ch; cout<<"i: insert s: search r: remove d: display \n"; cin>>ch; string name;

		switch(ch)
		{
			case 'i': 	cin>>name; insert(&root,name);
						break;
			case 's': 	cin>>name; cout<<search(&root,name,0)<<"\n";
						break;
			case 'r': 	cin>>name; cout<<search(&root,name,1)<<"\n";
						break;
			case 'd': 	display(&root,"");
						break;
			default : exit(0);
		}
	}

	return 0;
}