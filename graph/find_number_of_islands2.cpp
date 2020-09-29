#include<bits/stdc++.h>
using namespace std;
#define Vect vector<vector<int>>
#define display(i,j,n,m,a) for(int i=0; i<n; i++) { for(int j=0; j<m; j++) cout<<a[i][j]<<" "; cout<<"\n"; }

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
	int n,m,island_count=0,k; cin>>n>>m>>k; vector<vector<int>> graph(n,vector<int>(m));

	vector<pair<int,int>> p;

	while(k--)
	{
		int x,y; cin>>x>>y; graph[x][y]=1; p.push_back({x,y});
	}

	//display(i,j,n,m,graph);

	for(auto i=p.begin(); i!=p.end(); i++)
	{
		int x=i->first,y=i->second;

		if(graph[x][y])
		{
			island_count++; dfs(graph,x,y,n,m);
		}
	}

	cout<<island_count<<"\n";

	return 0;
}