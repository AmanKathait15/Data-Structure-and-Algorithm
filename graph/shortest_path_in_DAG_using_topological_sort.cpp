#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>

//https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/

void topological_sort(vector<Pair> graph[],vector<int> &op,bool visited[],int u)
{
	visited[u]=1;

	for(auto i = graph[u].begin(); i!=graph[u].end(); i++)
	{
		if(!visited[i->first]) topological_sort(graph,op,visited,i->first);
	}

	op.push_back(u);
}

void single_src_shortest_path(vector<Pair> graph[],int V,int src)
{
	vector<int> op,dist(V,INT_MAX);

	bool visited[V]={0}; dist[src]=0;

	for(int i=0; i<V; i++) if(!visited[i]) topological_sort(graph,op,visited,i);

	for(auto i=op.rbegin(); i!=op.rend(); i++)
	{
		int u = *i;

		if(dist[u]!=INT_MAX)
		{
			for(auto j = graph[u].begin(); j!=graph[u].end(); j++)
			{
				int v = j->first , w = j->second;

				if(dist[v]>dist[u]+w)	dist[v] = dist[u]+w;
			}
		}
	}

	for(auto i=op.begin(); i!=op.end(); i++) cout<<*i<<" ";
}

int main()
{
	int V,E,src; cin>>V>>E; vector<Pair> graph[V]; 

	for(int i=0; i<E; i++)
	{
		int u,v,w; cin>>u>>v>>w; graph[u].push_back({v,w}); // directed edge
	}

	cout<<"enter source node : "; cin>>src;

	single_src_shortest_path(graph,V,src);

	return 0;
}

// Test Case

/*
0 1 5
0 2 3
1 3 6
1 2 2
2 4 4
2 5 2
2 3 7
3 4 -1 
4 5 -2
*/

/*
4 5
0 1 1
0 2 4
1 2 2
1 3 6
2 3 3
*/

/*
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 8 2
7 8 7
7 6 1
8 6 6
6 5 2
2 3 7
2 5 4
5 3 14
5 4 10
3 4 9
*/

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
4 3
3 0 1 0 2 0
*/