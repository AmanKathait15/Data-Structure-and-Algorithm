#include<bits/stdc++.h>
using namespace std;
#define num long long int

int main()
{
	num t;
	cin>>t;
	while(t--)
	{
		num x,n,m;
		cin>>x>>n>>m;

		while(n-- && x>0)
		{
			num tmp;
			tmp=(x/2)+10;
			if(tmp>x) break;
			else x = tmp;
		}
		while(m-- && x>0)
		{
			x-=10;
		}
		if(x)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}