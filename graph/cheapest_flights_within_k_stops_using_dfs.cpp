#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/cheapest-flights-within-k-stops/

struct node 
{
	int y;
	int cost=0;
	int stop_count=0;
};

void dfs(vector<node> graph[],node s,int dst,int k,int &fair)
{
	if(s.y == dst) fair = min(fair,s.cost);

	for(auto i=graph[s.y].begin(); i!=graph[s.y].end(); i++)
	{
		node tmp = *i; tmp.cost+=s.cost; tmp.stop_count=s.stop_count+1;

		if(tmp.cost<fair and tmp.stop_count<=k)	dfs(graph,tmp,dst,k,fair);
	}
}

int main()
{
	int V,E,k; cin>>V>>E>>k; vector<node> graph[V]; k++; 

	for(int i=0; i<E; i++)
	{
		int x,y,w; cin>>x>>y>>w; node tmp = {.y = y , .cost = w };

		graph[x].push_back(tmp);
	}

	int src,dst,fair=INT_MAX; cin>>src>>dst; node s; s.y=src;

	dfs(graph,s,dst,k,fair);

	cout<<fair<<"\n";

	return 0;
}