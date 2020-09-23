#include<bits/stdc++.h> 
using namespace std; 
#define num int

num minCoins(vector<num> &coins, vector<num> &dp, num n, num v) 
{
	dp[0] = 0;

	for (num i=1; i<=v; i++) 
	{  
		for (num j=0; j<n; j++) 
		{
			if (coins[j] <= i) 
			{ 
				num sub_res = dp[i-coins[j]]; 
				
				if (sub_res + 1 < dp[i]) 	dp[i] = sub_res + 1; 
			}
		}

		for(num k=0; k<=v; k++) cout<<dp[k]<<" "; cout<<"\n";
	} 

	return dp[v]; 
} 

int main() 
{ 
	num n,v; cin>>n>>v; vector<num> coins(n),dp(v+1,INT_MAX-1);

	for(num i=0; i<n; i++) cin>>coins[i];
	
	cout<< minCoins(coins , dp , n, v);

	return 0; 
}