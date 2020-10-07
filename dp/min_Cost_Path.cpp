#include<bits/stdc++.h>
using namespace std;
#define Grid vector<vector<int>>

int min_Cost_Path(Grid &g,int n,int m)
{
	if(n<0 or m<0) return INT_MAX;

	if(n==0 and m==0) return g[0][0];

	return g[n][m] + min(min(min_Cost_Path(g,n,m-1),min_Cost_Path(g,n-1,m)),min_Cost_Path(g,n-1,m-1));
}

int main()
{
	int n,m; cin>>n>>m; Grid g(n);

	for(int i=0; i<n; i++) for(int j=0; j<m; j++)
	{
		int cost; cin>>cost; g[i].push_back(cost);
	}

	cout<<min_Cost_Path(g,n-1,m-1)<<"\n";

	return 0;
}