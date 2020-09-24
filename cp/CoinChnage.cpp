#include<bits/stdc++.h>
#define num long int
using namespace std;

/*
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5
*/

num CoinChnage(num arr[],num n,num k)
{
	if(k==0)	return 1;	//found one way(combination) to give change
	
	if(k<0) return 0;

	if(n<=0 && k>=1) return 0;

	return CoinChnage(arr,n-1,k) + CoinChnage(arr,n,k-arr[n-1]);	//exluding and including ith coin
}



int main()
{
	num t; cin>>t;

	while(t--)
	{
		num n,k; cin>>n>>k;

		num arr[n];

		for(num i=0; i<n; i++)	cin>>arr[i];

		cout<<CoinChnage(arr,n,k);
	}

	return 0;
}