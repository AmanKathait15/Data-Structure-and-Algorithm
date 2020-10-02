#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/possible-bipartition/

int main()
{
	int n; cin>>n; vector<pair<int,int>> v;

	while(n--)
	{
		int x,y; cin>>x>>y; v.push_back({x,y});
	}

	unordered_set<int> s1,s2; bool flag = 1;

	s1.insert(v[0].first),s2.insert(v[0].second);

	for(int i=1; i<v.size(); i++)
	{
		int x,y; x=v[i].first; y=v[i].second; bool fxs1=0,fys1=0,fxs2=0,fys2=0;

		if(s1.find(x)!=s1.end()) fxs1=1;
		if(s2.find(x)!=s2.end()) fxs2=1;
		if(s1.find(y)!=s1.end()) fys1=1;
		if(s2.find(y)!=s2.end()) fys2=1;

		if((fxs1 and fys1) or (fxs2 and fys2))	{ flag=0; break; }
		
		else if(fxs1 and !fys2) s2.insert(y);
		else if(fxs2 and !fys1) s1.insert(y);
		else if(fys1 and !fxs2) s2.insert(x);
		else if(fys2 and !fxs1) s1.insert(x);
		else 					s1.insert(x),s2.insert(y);

		//cout<<"\n set1 : "; for(auto i=s1.begin(); i!=s1.end(); i++) cout<<*i<<" ";
		//cout<<"\n set2 : "; for(auto i=s2.begin(); i!=s2.end(); i++) cout<<*i<<" ";
	}

	cout<<flag<<"\n";

	return 0;
}