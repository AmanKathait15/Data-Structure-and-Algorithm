#include<bits/stdc++.h>
using namespace std;

map<int,int> mp({{2,1},{3,1},{4,2},{5,1},{6,3},{7,1},{8,4},{9,2}});
map<int,int> prime({{2,1},{3,1},{5,1},{7,1},{11,1},{13,1},{17,1},{19,1},{23,1},
{29,1},{31,1},{37,1},{41,1},{43,1},{47,1},{53,1},{59,1},{61,1},
{67,1},{71,1},{73,1},{79,1},{83,1},{89,1},{97,1}});

int find(int n)
{
	if(prime[n]) return 1;
	if(mp[n]) return mp[n];

	int ans = 0;

	for(int i=2; i<=n/2; i++)
	{
		if(n%i==0)
		{
			if(i<10) ans += mp[i];
			else ans += find(i);
		}
	}

	return ans;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n; cin>>n; cout<<find(n)<<"\n"

	return 0;
}