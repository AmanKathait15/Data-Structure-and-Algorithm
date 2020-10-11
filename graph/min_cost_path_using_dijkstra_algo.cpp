#include<bits/stdc++.h>
using namespace std;
#define Grid vector<vector<int>>

//https://www.geeksforgeeks.org/min-cost-path-dp-6/

// all 8 directions

/*int dx[] = {1,-1, 0, 0, 1, 1,-1,-1}; 
int dy[] = {0, 0, 1,-1, 1,-1, 1,-1}; */

// up down left right

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1,-1};

struct Cell{ 
	int x; 
	int y; 
	int cost; 
}; 

class mycomparison 
{ 
public: 
bool operator() (const Cell &lhs, const Cell &rhs) const
{ 
	return (lhs.cost > rhs.cost); 
} 
};  

int min_Cost_Path(Grid &cost,int n,int m)
{
	Grid dp(n,vector<int>(m,INT_MAX)) , visited(n,vector<int>(m,0));

	priority_queue<Cell, vector<Cell>, mycomparison> pq; 

	dp[0][0] = cost[0][0];

	pq.push({0,0,cost[0][0]});

	while(!pq.empty())
	{
		Cell c = pq.top(); pq.pop();

		if(visited[c.x][c.y]) continue;

		visited[c.x][c.y] = 1;

		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++) 
			{
				if(dp[i][j] == INT_MAX) cout<<"INF ";
				else 					cout<<dp[i][j]<<" ";
			} 	cout<<"\n";
		}		cout<<"\n";

		for(int i=0; i<4; i++)
		{
			int x = c.x + dx[i] , y = c.y + dy[i];

			if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]) { 
				
				dp[x][y] = min(dp[x][y],dp[c.x][c.y] + cost[x][y]); 
				
				pq.push({x, y, dp[x][y]}); 
			}
		}
	}

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

/*
4 5
1 8 8 1 5  
4 1 1 8 1  
4 2 8 8 1 
1 5 8 8 1
*/

/*
5 5
31 100 65 12 18
10 13 47 157 6
100 113 174 11 33
88 124 41 20 140
99 32 111 41 20
*/