#include<bits/stdc++.h>
using namespace std;

void dfs(list<int> g[],bool visited[],int i)
{
	visited[i] = 1;

	for(auto j=g[i].begin(); j!=g[i].end(); j++)
	{
		int u = *j;	if(!visited[u])	dfs(g,visited,u);
	}
}

bool isConnected(list<int> g[],int V)
{

	/*for(int i=0; i<V; i++)
	{
		cout<<"\n"<<i<<" : "; for(auto j=g[i].begin(); j!=g[i].end(); j++)	cout<<*j<<" ";
	}	cout<<"\n";*/

	bool visited[V]={0};	dfs(g,visited,0);

	//for(int i=0; i<V; i++) cout<<visited[i]<<" "; cout<<"\n";

	for(int i=0; i<V; i++) if(visited[i]==0) return 0;

	return 1;
}

int main()
{
	int V,E; cin>>V>>E; list<int> g[V];

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

		g[x].remove(y); // O(n)
		g[y].remove(x); // O(n)

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