#include<bits/stdc++.h>
#define num long int
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	short t; cin>>t;

	while(t--)
	{
		num n,r0=0,r1=0,r2=0; cin>>n;

		for(num i=0; i<n; i++)
		{
			num x; cin>>x;

			if(x%3==0)	r0++;
			else if(x%3==1) r1++;
			else r2++;
		}

		if(r0>(r1+r2+1) || (r0<r1 && r0<r2 && r1!=0 r2!=0))	cout<<"No\n";
		else			cout<<"Yes\n";
	}

	return 0;
}