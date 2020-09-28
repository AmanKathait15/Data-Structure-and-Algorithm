#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> g,bool visited[],int i,int V)
{
	for(int j=0; j<V; j++)
	{
		if(g[i][j]==1 and !visited[j])
		{
			visited[j]=1; dfs(g,visited,j,V);
		}
	}
}

bool isConnected(vector<vector<int>> g,int V)
{
	bool visited[V]={0}; visited[0]=1;

	dfs(g,visited,0,V);

	//for(int i=0; i<V; i++) cout<<visited[i]<<" "; cout<<"\n";

	for(int i=0; i<V; i++) if(visited[i]==0) return 0;

	return 1;
}

int main()
{
	int V,E; cin>>V>>E; vector<vector<int>> g(V);

	vector<pair<int,int>> edge,bridge;

	for(int i=0; i<V; i++)
	for(int j=0; j<V; j++)
		g[i].push_back(0);

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; g[x][y]=1; g[y][x]=1; edge.push_back({x,y});
	}

	for(auto i=edge.begin(); i!=edge.end(); i++)
	{
		int x=i->first,y=i->second;  g[x][y]=0; g[y][x]=0; // remove edge

		if(!isConnected(g,V))
		{
			bridge.push_back({x,y});
		}

		g[x][y]=1; g[y][x]=1; // add edge again
	}

	for(auto i=bridge.begin(); i!=bridge.end(); i++) cout<<i->first<<" "<<i->second<<"\n";

	return 0;
}