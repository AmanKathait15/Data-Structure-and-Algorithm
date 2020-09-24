#include<bits/stdc++.h>
#define num unsigned long int
using namespace std;

/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/


bool solve(num arr[],num n,num k)
{
	num dp[n+1][k+1];

	for(num j=0; j<=k; j++)
		dp[0][j]=0;
	for(num i=0; i<=n; i++)
		dp[i][0]=1;

	for(num i=1; i<=n; i++)
	{
		for(num j=1; j<=k; j++)
		{
			if(arr[i-1]>j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
		}
	}


	return dp[n][k];
}




int main()
{
	num t; cin>>t;

	while(t--)
	{
		num n,k; cin>>n>>k;

		num arr[n];

		for(num i=0; i<n; i++)	cin>>arr[i];

		cout<<solve(arr,n,k)<<"\n";

	}

	return 0;
}