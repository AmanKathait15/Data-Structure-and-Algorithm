#include<bits/stdc++.h>
using namespace std;

void dfs(vector<pair<int,int>> graph[],vector<int> &dist,int u)
{
	for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
	{
		int v=i->first,w=i->second;

		if(dist[v] > dist[u]+w)
		{
			dist[v]=dist[u]+w; dfs(graph,dist,v);
		}
	}
}

int main()
{
	int V,E,src; cin>>V>>E; vector<pair<int,int>> graph[V]; vector<int> dist(V,INT_MAX);

	for(int i=0; i<E; i++)
	{
		int x,y,w; cin>>x>>y>>w; graph[x].push_back({y,w}); graph[y].push_back({x,w});
	}

	cout<<"enter source node : "; cin>>src;

	dist[src] = 0;

	dfs(graph,dist,src);

	for(auto i=dist.begin(); i!=dist.end(); i++) cout<<*i<<" "; cout<<"\n";

	return 0;
}

