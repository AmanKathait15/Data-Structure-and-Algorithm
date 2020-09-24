#include<bits/stdc++.h>
using namespace std;
#define num long int

int main()
{
	num t;
	cin>>t;
	while(t--)
	{
		num n,ans;
		cin>>n; ans=n/2;
		map<num,num> mp;
		vector<num> arr(n);
		for(num i=0; i<n; i++)
		{
			cin>>arr[i];
			mp[arr[i]]++;
		}
		num same=0,u=0;
		for(auto i=mp.begin(); i!=mp.end(); i++)
		{
			if((i->second)>same) same=i->second;
			if(i->second==1)
				u++;
		}
		num unique = mp.size();
		num ans1 = min(same,unique-1),ans2 = min(same-1,unique);
		cout<<max(ans2,ans1)<<"\n";
	}
	return 0;
}