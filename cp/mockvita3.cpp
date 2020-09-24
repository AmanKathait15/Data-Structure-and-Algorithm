#include<bits/stdc++.h>
using namespace std;
#define num int

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	num minl,maxl,minw,maxw,ans = 0;	cin>>minl>>maxl>>minw>>maxw;

	for(num i=minl; i<=maxl; i++)
	{
		for(num j=minw; j<=maxw; j++)
		{
			//cout<<i<<" "<<j<<"\n";
			num x=i,y=j;

			while(x!=y)
			{
				ans++;
				if(x>y) x-=y;
				else y-=x;
			}
			ans++;
		}
	}

	cout<<ans<<"\n";

	return 0;
}