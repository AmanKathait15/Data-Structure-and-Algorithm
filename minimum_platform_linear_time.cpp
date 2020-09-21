#include <bits/stdc++.h>
using namespace std;
#define num int

num minium_platform(multimap<num,bool> &mp)
{
	num m=0,p=0;

	for(auto i=mp.begin(); i!=mp.end(); i++)
	{
		if(i->second) p++;
		else p--;

		if(p>m) m=p;
	}
	return m;
}


int main() {
	//code

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin>>t;
	
	while(t--)
	{
		num n; cin>>n; num a[n],d[n]; multimap<num,bool> mp;
		
		for(num i=0; i<n; i++) 
		{
			cin>>a[i]; mp.insert({a[i],1});
		}
		for(num i=0; i<n; i++)
		{
			cin>>d[i]; mp.insert({d[i],0});
		}
		cout<<minium_platform(mp)<<"\n";
	}
	return 0;
}