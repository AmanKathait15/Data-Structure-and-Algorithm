#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/topological-sorting/

void topological_sort(vector<int> graph[],vector<int> &op,bool visited[],int u)
{
	visited[u]=1;

	for(auto i = graph[u].begin(); i!=graph[u].end(); i++)
	{
		if(!visited[*i]) topological_sort(graph,op,visited,*i);
	}

	op.push_back(u);
}

int main()
{
	int V,E; cin>>V>>E; vector<int> op, graph[V];	// graph must be DAG for topological sort

	bool visited[V] = {0};

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; graph[x].push_back(y); // directed edge
	}

	for(int i=0; i<V; i++)
		if(!visited[i])	
			topological_sort(graph,op,visited,i);

	for(auto i=op.rbegin(); i!=op.rend(); i++) cout<<*i<<" ";

	return 0;
}

// Test Case

/*
6 6
5 2 
5 0 
4 0 
4 1 
2 3 
3 1
*/

/*
6 6
5 0 5 2 2 3 4 0 4 1 1 3
*/

/*
3 4
3 0 1 0 2 0
*/