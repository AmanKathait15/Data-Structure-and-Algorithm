#include<bits/stdc++.h>
using namespace std;

int min_ins(string str,int n)
{
	int dp[n][n]; memset(dp,0,sizeof(dp));

	for(int gap = 1; gap<n; gap++)
	{
		for(int l=0,h=gap; h<n; l++,h++)
		{
			dp[l][h] = (str[l]==str[h])? dp[l+1][h-1] : min(dp[l][h-1] ,dp[l+1][h] ) + 1;
		}

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}	cout<<"\n\n";
	}

	return dp[0][n-1];
}

int main()
{
	int t; cin>>t;
	
	while(t--)
	{
		string str; cin>>str; cout<<min_ins(str,str.length())<<"\n";
	}

	return 0;
}