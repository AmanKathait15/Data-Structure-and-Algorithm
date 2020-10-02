#include<bits/stdc++.h>
using namespace std;
#define RED 1
#define GREEN 0

//https://leetcode.com/problems/possible-bipartition/submissions/
//https://www.geeksforgeeks.org/bipartite-graph/

bool bfs(vector<int> graph[],vector<short> &color,int u)
{
	queue<int> Q; Q.push(u); color[u]=RED;

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();

		for(auto i=graph[u].begin(); i!=graph[u].end(); i++)
		{
			int v = *i;

			if(u==v) return 1; // self loop

			if(color[v]==-1) 
			{ 
				Q.push(v); color[v] = 1 - color[u]; 
			}
			else if(color[v]==color[u])   return 1;	// contain odd length cycle
		}		
	}

	return 0;
}

bool isBipartite(vector<int> graph[],int V)
{
	vector<short> color(V,-1);

	for(int i=1; i<V; i++) if(color[i]==-1) if(bfs(graph,color,i)) return 0;	return 1;	// loop to check all posibilty graph may also disconnected 
}

int main()
{
	int V,E; cin>>V>>E; V+=1; vector<int> graph[V];

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; graph[x].push_back(y); graph[y].push_back(x); // undirected graph
	}

	if(isBipartite(graph,V)) 	cout<<"Yes\n";
	else 						cout<<"No\n";

	return 0;
}