#include<bits/stdc++.h>
using namespace std;

//The assumption of this approach is that there are no parallel edges between any two vertices.

bool isCycle(vector<int> graph[],vector<bool> &visited,int src)	// dfs
{
	visited[src]=1;

	for(auto i=graph[src].begin(); i!=graph[src].end(); i++)
	{
		if(!visited[*i]) if(isCycle(graph,visited,*i))  return 1;
		else 			 if(src != *i) 					return 1; // contain backedge
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

	if(isCycle(graph,visited,0)) 	cout<<"contain cycle\n";
	else 						 	cout<<"not contain cycle \n";

	return 0;
}