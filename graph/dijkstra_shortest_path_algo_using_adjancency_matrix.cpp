#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int>

void shortest_dist(vector<vector<int>> graph,vector<int> &dist,int u)
{
	priority_queue<Pair> pq; pq.push({0,u}); dist[u]=0; //int iter=0;

	while(!pq.empty())
	{
		Pair p = pq.top(); pq.pop(); u = p.second;

		//for(auto i=dist.begin(); i!=dist.end(); i++) cout<<*i<<" "; cout<<"\n";

		for(int i=0; i<graph[]; i++)
		{
			int v = i->first , w = i->second; //iter++;

			if(dist[v] > dist[u] + w)
			{
				dist[v]=dist[u] + w; pq.push({dist[v],v});
			}
		}
	}

	//cout<<iter<<"\n";
}

int main()
{
	int V,E,src; cin>>V>>E; vector<vector<int>> graph(V,vector<int>(V)); vector<int> dist(V,INT_MAX);

	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			cin>>graph[i][j];
		}
	}

	cout<<"enter source node : "; cin>>src;

	shortest_dist(graph,dist,src);

	for(auto i=dist.begin(); i!=dist.end(); i++) cout<<*i<<" "; cout<<"\n";

	return 0;
}

// Test Case

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