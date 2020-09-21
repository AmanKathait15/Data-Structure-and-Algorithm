#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin>>t;
	
	while(t--)
	{
		int n,ans=0,c=0,x; cin>>n; bitset<10> b;

		for(int i=0; i<n; i++)
		{
			cin>>x; x?b[i]=1:b[i]=0;
		}


		for(int i=n-1; i>=0; i--)
		{
			if(b[i]) ans+=c;
			else c++;
		}

		cout<<ans<<"\n";

	}

	return 0;
}