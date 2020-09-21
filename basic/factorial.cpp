#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin>>t;

	while(t--)
	{
		cout<<"enter a number : ";

		int n,f=1; cin>>n;

		for(int i=1; i<=n; i++) f*=i;

		cout<<f<<" ";
	}
	return 0;
}