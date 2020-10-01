#include<bits/stdc++.h>
using namespace std;
#define vect vector<vector<int>>

//https://www.geeksforgeeks.org/union-find/

bool dfs(vector<int> graph[],vector<bool> &visited,vector<bool> &recstack,int src)
{
	if(!visited[src])
	{
		visited[src] = 1;
		recstack[src]= 1;

		for(auto i=graph[src].begin(); i!=graph[src].end(); i++)
		{
			if(!visited[*i] and dfs(graph,visited,recstack,*i)) return 1;
			else if(recstack[*i])								return 1;
		}
	}

	recstack[src]=0;

	return 0;
}

bool isCycle(vector<int> graph[],int V)
{
	vector<bool> visited(V,0),recstack(V,0);

	for(int i=0; i<V; i++)
	{
		if(!visited[i]) if(dfs(graph,visited,recstack,i)) return 1;
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