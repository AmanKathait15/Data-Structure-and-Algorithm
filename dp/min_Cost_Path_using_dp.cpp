#include<bits/stdc++.h>
using namespace std;
#define Grid vector<vector<int>>

//https://www.geeksforgeeks.org/min-cost-path-dp-6/

int min_Cost_Path(Grid &dp,int n,int m)
{
	for(int j=1; j<m; j++) dp[0][j]+=dp[0][j-1];
	for(int i=1; i<n; i++) dp[i][0]+=dp[i-1][0];

	for(int i=1; i<n; i++)
	{
		for(int j=1; j<m; j++)
		{
			dp[i][j]+= min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
		}
	}

	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++) cout<<dp[i][j]<<" "; cout<<"\n";
	}	cout<<"\n";*/

	return dp[n-1][m-1];
}

int main()
{
	int n,m; cin>>n>>m; Grid g(n);

	for(int i=0; i<n; i++) for(int j=0; j<m; j++)
	{
		int cost; cin>>cost; g[i].push_back(cost);
	}

	cout<<min_Cost_Path(g,n,m)<<"\n";

	return 0;
}

// Test Case

/*
3 3
1 3 1
2 5 1
4 8 1
*/