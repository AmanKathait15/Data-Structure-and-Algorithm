#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY  1
#define BLACK 2

bool dfs(vector<int> graph[],vector<short> &color,int u)
{
	color[u] = GRAY;

	for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
	{
		int v=*i;

		if(color[v]==GRAY) return 1;

		if(color[v]==WHITE and dfs(graph,color,v)) return 1;
	}

	color[u] = BLACK;

	return 0;
}

bool isCycle(vector<int> graph[],int V)
{
	vector<short> color(V,WHITE);

	for(int i=0; i<V; i++)
	{
		if(!color[i]) if(dfs(graph,color,i)) return 1;
	}

	return 0;
}

int main()
{
	int V,E; cin>>V>>E; vector<int> graph[V];

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; graph[x].push_back(y);
	}

	if(isCycle(graph,V)) 		cout<<"contain cycle\n";
	else 						cout<<"not contain cycle \n";

	return 0;
}