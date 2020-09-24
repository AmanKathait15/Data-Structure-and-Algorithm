#include<bits/stdc++.h>
using namespace std;
#define num unsigned long long int

int main()
{
	num t;
	cin>>t;
	while(t--)
	{
		num n,ans;
		cin>>n;
		if(n%2==0)
			ans=(n/2)-1;
		else ans=(n/2);
		cout<<ans<<"\n";
	}
	return 0;
}