#include<bits/stdc++.h>
using namespace std;

//int iter=0;

void dfs(vector<pair<int,int>> graph[],vector<int> &dist,int u)
{
	//for(auto i=dist.begin(); i!=dist.end(); i++) cout<<*i<<" "; cout<<"\n";

	for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
	{
		int v=i->first,w=i->second;

		if(dist[v] > dist[u]+w)
		{
			dist[v]=dist[u]+w; dfs(graph,dist,v); //iter++;
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

	//cout<<iter;

	return 0;
}

// Test Case

/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 8 2
7 8 7
7 6 1
8 6 6
6 5 2
2 3 7
2 5 4
5 3 14
5 4 10
3 4 9
*/