#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],bool visited[],int parent[],int low[],int discover[],int u,int V,int ap[])
{
	static int timer = 1; int children = 0;

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
			parent[v] = u; children++;

			dfs(g,visited,parent,low,discover,v,V,ap);

			low[u] = min(low[u],low[v]);

			if(parent[u]==-1 and children>1) ap[i]=1;

			if(parent[u]!=-1 and low[v] >= discover[u]) ap[i]=1;
		}
		else if(v != parent[u]) low[u] = min(low[u],discover[v]);
	}
}

void print_articulation_point(vector<int> g[],int V)
{
	bool visited[V]={0}; int ap[V];

	int parent[V],low[V]={0},discover[V]={0};	memset(parent,-1,sizeof(parent));

	//for(int i=0; i<V; i++)	if(visited[i]==0)
	
	dfs(g,visited,parent,low,discover,0,V,ap);

	for(int i=0; i<V; i++) if(ap[i]) cout<<i<<"\n";
}

int main()
{
	int V,E; cin>>V>>E; vector<int> g[V];

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y;	g[x].push_back(y);	g[y].push_back(x);
	}

	print_articulation_point(g,V);

	return 0;
}