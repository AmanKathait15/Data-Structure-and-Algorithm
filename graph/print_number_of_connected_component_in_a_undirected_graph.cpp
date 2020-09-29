#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],bool visited[],int src)
{
	visited[src]=1;

	for(auto i=g[src].begin(); i!=g[src].end(); i++)
	{
		if(!visited[*i]) dfs(g,visited,*i);
	}
}

int main()
{
	int V,E; cin>>V>>E; vector<int> g[V];

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y;	g[x].push_back(y);	g[y].push_back(x);
	}

	bool visited[V]={0}; int c=0;

	cout<<"connected components in graph : ";

	for(int i=0; i<V; i++)	
	{
		if(!visited[i])
		{
			c++; dfs(g,visited,i); cout<<"\n"<<i<<" ";
		}
		else cout<<i<<" ";
	}

	return 0;
}