#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

bool compare(char x,char y)
{
	if(mp[x]==0 and mp[y]==0) return (x<y)?1:0;

	if(mp[y]==0) return 1;
	if(mp[x]==0) return 0;

	return (mp[x]>mp[y])?1:0;
}

int main()
{
	string str,ord; cin>>str>>ord; int n = ord.length();

	for(int i=0; i<n; i++) mp[ord[i]]=n-i;

	sort(str.begin(),str.end(),compare);

	cout<<str;

	return 0;
}