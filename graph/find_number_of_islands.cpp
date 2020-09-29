#include<bits/stdc++.h>
using namespace std;
#define Vect vector<vector<int>>

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

void dfs(Vect &graph,int i,int j,int n,int m)
{
	graph[i][j]=0;

	for(int k=0; k<8; k++)
	{
		int x = i+dx[k],y = j+dy[k];

		if(x>=0 and x<n and y>=0 and y<m and graph[x][y]==1)	dfs(graph,x,y,n,m);
	}
}

int main()
{
	int n,m,island_count=0; cin>>n>>m; vector<vector<int>> graph(n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int x; cin>>x; graph[i].push_back(x);
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		if(graph[i][j])
		{
			island_count++; dfs(graph,i,j,n,m);
		}
	}

	cout<<island_count<<"\n";

	return 0;
}