#include<bits/stdc++.h>
using namespace std;

int find(int parent[],int i)
{
	int tmp = i;

	while(i!=parent[i])
	{
		i=parent[i];
	}

	parent[tmp] = i;	// path compression

	return i;
}

bool bfs(vector<int> graph[],vector<bool> &visited,int parent[],int u)
{
	queue<int> Q; Q.push(u); visited[u]=1; parent[u]=u;

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
		{
			int v = *i;

			if(!visited[v])
			{
				Q.push(v); visited[v]=1; parent[v]=u;
			}
			else if(find(parent,u)==v) return 1;
		}
	}

	return 0;
}

bool isCycle(vector<int> graph[],int V)
{
	vector<bool> visited(V,0); int parent[V];

	for(int i=0; i<V; i++)
	{
		if(!visited[i]) if(bfs(graph,visited,parent,i)) return 1;
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