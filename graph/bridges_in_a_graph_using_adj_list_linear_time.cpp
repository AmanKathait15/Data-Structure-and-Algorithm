#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],bool visited[],int parent[],int low[],int discover[],int u,int V)
{
	static int timer = 1;

	visited[u]=1;	discover[u] = low[u] = timer++;

	//for(int i=0; i<V; i++) cout<<visited[i]<<" "; cout<<"\n";
	//for(int i=0; i<V; i++) cout<<parent[i]<<" "; cout<<"\n";
	//for(int i=0; i<V; i++) cout<<low[i]<<" "; cout<<"\n";
	//for(int i=0; i<V; i++) cout<<discover[i]<<" "; cout<<"\n\n\n";

	for(int j=0; j<g[u].size(); j++)
	{
		int v = g[u][j];

		if(!visited[v])
		{
			parent[v] = u;

			dfs(g,visited,parent,low,discover,v,V);

			low[u] = min(low[u],low[v]);

			if(low[v]>discover[u]) cout<<u<<" "<<v<<"\n";
		}
		else if(v != parent[u]) low[u] = min(low[u],discover[v]);
	}
}

void print_bridges(vector<int> g[],int V)
{
	bool visited[V]={0};

	int parent[V],low[V]={0},discover[V]={0};	memset(parent,-1,sizeof(parent));

	dfs(g,visited,parent,low,discover,0,V);
}

int main()
{
	int V,E; cin>>V>>E; vector<int> g[V];

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y;	g[x].push_back(y);	g[y].push_back(x);
	}

	print_bridges(g,V);

	return 0;
}