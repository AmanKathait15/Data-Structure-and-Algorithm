#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> bridegs;

void dfs(vector<int> g[],bool visited[],int parent[],int low[],int discover[],int u,int V,bool ap[])
{
	static int timer = 1; int children = 0;

	visited[u]=1;	discover[u] = low[u] = timer++;

	for(int j=0; j<g[u].size(); j++)
	{
		int v = g[u][j];

		if(!visited[v])
		{
			parent[v] = u; children++;

			dfs(g,visited,parent,low,discover,v,V,ap);

			low[u] = min(low[u],low[v]);

			if(low[v]>discover[u]) bridegs.push_back({u,v});

			if(parent[u]==-1 and children>1) ap[u]=1;

			if(parent[u]!=-1 and low[v] >= discover[u]) ap[u]=1;
		}
		else if(v != parent[u]) low[u] = min(low[u],discover[v]);
	}
}

void print_bridges(vector<int> g[],int V)
{
	bool visited[V]={0},ap[V]={0};

	int parent[V],low[V]={0},discover[V]={0};	memset(parent,-1,sizeof(parent));

	dfs(g,visited,parent,low,discover,0,V,ap);

	cout<<"articulation point : \n";

	for(int i=0; i<V; i++) if(ap[i]) cout<<i<<"\n";

	cout<<"bridegs : \n";

	for(auto i=bridegs.begin(); i!=bridegs.end(); i++) cout<<i->first<<" "<<i->second<<"\n";
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