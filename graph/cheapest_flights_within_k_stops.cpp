#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/cheapest-flights-within-k-stops/

struct node 
{
	int y;
	int cost=0;
	int stop_count=0;
};

void bfs(vector<node> graph[],int src,int dst,int k,int &fair)
{
	queue<node> Q; node s; s.y=src; Q.push(s);

	while(!Q.empty())
	{
		s = Q.front(); Q.pop();

		cout<<s.y<<" "<<s.cost<<" "<<s.stop_count<<"\n";

		if(s.y==dst)
		{
			if(s.cost<fair) fair=s.cost;
		}

		for(auto i=graph[s.y].begin(); i!=graph[s.y].end(); i++)
		{
			node tmp = *i; tmp.cost+=s.cost; tmp.stop_count=s.stop_count+1;

			if(tmp.cost<fair and tmp.stop_count<=k)	Q.push(tmp);
		}
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

	int src,dst,fair=INT_MAX; cin>>src>>dst;

	bfs(graph,src,dst,k,fair);

	cout<<fair<<"\n";

	return 0;
}