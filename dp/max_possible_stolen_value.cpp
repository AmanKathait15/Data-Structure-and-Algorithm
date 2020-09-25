#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

int maxStole(int a[],int n)
{
	if(n<=0) return 0;	int dp[n];
	if(n>=1) dp[0]=a[0];
	if(n>=2) dp[1]=max(a[0],a[1]);

	for(int i=2; i<n; i++)
	{
		dp[i] = max(dp[i-1],dp[i-2]+a[i]); cout<<dp[i]<<" ";
	}

	return dp[n-1];
}

int main()
{	
	int t; cin>>t;
	
	while(t--)
	{
	    int n; cin>>n; int a[n];
	    
	    for(int i=0; i<n; i++) cin>>a[i];
	    
	    cout<<maxStole(a,n)<<"\n";
	}
	
	return 0;
}