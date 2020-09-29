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

bool isDisconnected(bool visited[],int V)
{
	for(int i=0; i<V; i++) if(visited[i]==0) return 1; return 0;
}

int main()
{
	int V,E; cin>>V>>E; list<int> g[V];

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y;	g[x].push_back(y);	g[y].push_back(x);
	}

	bool visited[V]={0}; visited[0]=1;	dfs(g,visited,1);
	
	if(isDisconnected(visited,V)) cout<<0<<"\n";

	for(int i=1; i<E; i++)
	{
		memset(visited,0,sizeof(visited)); visited[i]=1;

		dfs(g,visited,0);

		if(isDisconnected(visited,V)) cout<<i<<"\n";
	}

	return 0;
}