#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t;

	while(t--)
	{
		cout<<"enter a number : ";

		int n,sum=0,tmp; cin>>n; tmp = n;

		while(n)
		{
			sum+=(int)pow(n%10,3);
			n/=10;
		}

		cout<<sum<<" ";

		if(sum == tmp) cout<<"yes\n";
		else cout<<"NO\n";
	}
	return 0;
}