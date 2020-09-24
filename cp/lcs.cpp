// longest common subsequence np hard problem

#include <bits/stdc++.h>
using namespace std;

string str;

void seq(set<string> &a,int n,int l)
{
	for (int i = 0; i < n; i++)
	{
		string s="";
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			s+=str[j];
		}	a.insert(s);
	}
}

void lcs(set<string> &s1,set<string> &s2)
{
	for (auto i=s1.begin(); i!= s1.end(); ++i)
	{
		for (auto j=s2.begin(); j!= s2.end(); ++j)
		{
			if((*i)==(*j))
				cout<<(*i)<<" ";
		}
	}
}

int main()
{
	int l,n;

	set<string> s1,s2;

	cin>>str;
	l = str.length();
	n = pow(2,l);
	seq(s1,n,l);


	cin>>str;
	l = str.length();
	n = pow(2,l);
	seq(s2,n,l);

	lcs(s1,s2);

	return 0;
}
