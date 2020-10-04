#include<bits/stdc++.h>
using namespace std;

void bfs(vector<pair<int,int>> graph[],vector<int> &dist,int u)
{
	queue<int> Q; dist[u]=0; Q.push(u); int iter=0;

	while(!Q.empty())
	{
		u = Q.front(); Q.pop(); iter++;

		//for(auto i=dist.begin(); i!=dist.end(); i++) cout<<*i<<" "; cout<<"\n";

		for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
		{
			int v=i->first,w=i->second;

			if(dist[v] > dist[u]+w)
			{
				Q.push(v); dist[v]=dist[u]+w;
			}
		}
	}

	cout<<iter<<"\n";
}

int main()
{
	int V,E,src; cin>>V>>E; vector<pair<int,int>> graph[V]; vector<int> dist(V,INT_MAX);

	for(int i=0; i<E; i++)
	{
		int x,y,w; cin>>x>>y>>w; graph[x].push_back({y,w}); graph[y].push_back({x,w});
	}

	cout<<"enter source node : "; cin>>src;

	bfs(graph,dist,src);

	for(auto i=dist.begin(); i!=dist.end(); i++) cout<<*i<<" "; cout<<"\n";

	return 0;
}

