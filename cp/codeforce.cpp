#include<bits/stdc++.h>
using namespace std;
#define num long long int

int main()
{
	num n,common = 0;
	cin>>n;

	map<num,num> mp1,mp2;

	for(num i=0; i<n; i++)
	{
		num x;
		cin>>x;

		mp1[x]+=x;
	}

	for(auto i=mp.begin(); i!=mp.end(); i++)
	{
		mp2[i->second]=i->first;
	}

	

	cout<<count<<"\n";

	return 0;
}