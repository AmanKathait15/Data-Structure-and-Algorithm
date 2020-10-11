#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

void topological_sort(vector<int> graph[],vector<int> &in_degree,int V)
{
	queue<int> Q; int Count = 0; vector<int> op;

	for(int i=0; i<V; i++) if(in_degree[i]==0) Q.push(i);

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		op.push_back(u); Count++;

		for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
		{
			in_degree[*i]--; if(in_degree[*i]==0) Q.push(*i);
		}
	}

	if(Count!=V)
	{
		cout<<"graph is not DAG"; op.clear(); return ;
	}

	for(auto i=op.begin(); i!=op.end(); i++) cout<<*i<<" ";
}

int main()
{
	int V,E; cin>>V>>E; vector<int> op,in_degree(V,0), graph[V];	// graph must be DAG for topological sort

	for(int i=0; i<E; i++)
	{
		int u,v; cin>>u>>v; graph[u].push_back(v); // directed edge

		in_degree[v]++;
	}

	topological_sort(graph,in_degree,V);

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