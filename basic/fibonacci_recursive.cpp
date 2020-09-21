#include<bits/stdc++.h>
using namespace std;

int dp[1000] = {0};

int fib(int n)
{
	if(n==0 || n==1) return n;

	if(dp[n]!=0) return dp[n];

	dp[n] = (fib(n-1)+fib(n-2));

	return dp[n];
}

int main()
{
	int t; cin>>t;

	while(t--)
	{
		cout<<"enter a number : ";

		int n,f=1; cin>>n; cout<<fib(n-1)<<"\n";
	}

	return 0;
}