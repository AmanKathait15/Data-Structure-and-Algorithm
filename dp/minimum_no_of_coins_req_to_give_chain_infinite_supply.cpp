#include<bits/stdc++.h> 
using namespace std;
#define num int

int minCoins(int a[], int n, int val)
{
	if(val == 0)	return 0;

	if(val < 0 || n == 0)	return INT_MAX-1;

	return min(minCoins(a, n-1, val-a[n-1])+1, minCoins(a, n-1, val));
}

int main() 
{ 
	num n,v; cin>>n>>v; num coins[n];

	for(num i=0; i<n; i++) cin>>coins[i];

	cout<<minCoins(coins,n,v)<<"\n";

	return 0; 
} 