#include<bits/stdc++.h>
using namespace std;
#define Grid vector<vector<int>>
#define Pair pair<int,pair<int,int>> 

//https://www.geeksforgeeks.org/min-cost-path-dp-6/

// all 8 directions

/*int dx[] = {1,-1, 0, 0, 1, 1,-1,-1}; 
int dy[] = {0, 0, 1,-1, 1,-1, 1,-1}; */

// up down left right

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0, 1,-1};

int min_Cost_Path(Grid &cost,int n,int m)
{
	Grid dp(n,vector<int>(m,INT_MAX)) , visited(n,vector<int>(m,0));

	priority_queue<Pair,vector<Pair>,greater<Pair>> pq;	// min heap

	dp[0][0] = cost[0][0];

	pq.push({cost[0][0],{0,0}});

	while(!pq.empty())
	{
		Pair p = pq.top(); pq.pop();

		int X = p.second.first , Y = p.second.second , x,y;

		if(visited[X][Y]) continue;

		visited[X][Y] = 1;

		/*for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++) 
			{
				if(dp[i][j] == INT_MAX) cout<<"INF ";
				else 					cout<<dp[i][j]<<" ";
			} 	cout<<"\n";
		}		cout<<"\n";*/

		x = X + dx[0] , y = Y + dy[0];

		if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]) { 
			
			dp[x][y] = min(dp[x][y],dp[X][Y] + cost[x][y]); 
			
			pq.push({dp[x][y],{x, y}}); 
		}

		x = X + dx[1] , y = Y + dy[1];

		if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]) { 
			
			dp[x][y] = min(dp[x][y],dp[X][Y] + cost[x][y]); 
			
			pq.push({dp[x][y],{x, y}}); 
		}

		x = X + dx[2] , y = Y + dy[2];

		if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]) { 
			
			dp[x][y] = min(dp[x][y],dp[X][Y] + cost[x][y]); 
			
			pq.push({dp[x][y],{x, y}}); 
		}

		x = X + dx[3] , y = Y + dy[3];

		if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]) { 
			
			dp[x][y] = min(dp[x][y],dp[X][Y] + cost[x][y]); 
			
			pq.push({dp[x][y],{x, y}}); 
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