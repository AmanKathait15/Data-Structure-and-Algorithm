#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/

//The assumption of this approach is that there are no parallel edges between any two vertices.

bool isCycle(vector<int> graph[],int V,int src)
{
	queue<int> Q; Q.push(src);

	vector<int> parent(V,-1),visited(V,0);

	while(!Q.empty())
	{
		int src = Q.front(); Q.pop(); visited[src]=1;

		for(int i=0; i<graph[src].size(); i++)
		{
			int u = graph[src][i];

			if(!visited[u])
			{
				Q.push(u); parent[u]=src;
			}
			else if(parent[src]!=u) return 1;
		}		
	}

	return 0;
}

int main()
{
	int V,E; cin>>V>>E; vector<int> graph[V]; vector<bool> visited(V,0);

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; graph[x].push_back(y); graph[y].push_back(x);
	}

	if(isCycle(graph,V,0)) 			cout<<"contain cycle\n";
	else 						 	cout<<"not contain cycle \n";

	return 0;
}