#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],bool visited[],int i)
{
	for(int j=0; j<g[i].size(); j++)
	{
		if(!visited[g[i][j]])
		{
			visited[g[i][j]]=1; dfs(g,visited,g[i][j]);
		}
	}
}

bool isConnected(vector<int> g[],int V)
{
	bool visited[V+1]={0}; visited[0]=1;

	dfs(g,visited,0);

	for(int i=0; i<V; i++) cout<<visited[i]<<" "; cout<<"\n";

	for(int i=0; i<V; i++) if(visited[i]==0) return 0;

	return 1;
}

int main()
{
	int V,E; cin>>V>>E; vector<int> g[V];

	vector<pair<int,int>> edge,bridge;

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; edge.push_back({x,y});

		g[x].push_back(y);
		g[y].push_back(x);
	}

	for(auto i=edge.begin(); i!=edge.end(); i++)
	{
		int x=i->first,y=i->second;

		remove(g[x].begin(),g[x].end(),y); // O(n)
		remove(g[y].begin(),g[y].end(),x); // O(n)

		if(!isConnected(g,V))
		{
			bridge.push_back({x,y});
		}

		g[x].push_back(y);	
		g[y].push_back(x); // add edge again
	}

	cout<<"Bridges in given graph are :\n";

	for(auto i=bridge.begin(); i!=bridge.end(); i++) cout<<i->first<<" "<<i->second<<"\n";

	return 0;
}