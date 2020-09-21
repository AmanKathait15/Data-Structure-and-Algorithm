#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> g[],int v,int i)
{
	queue<int> Q; Q.push(i); bool visited[v]; memset(visited,0,sizeof(visited));

	while(!Q.empty())
	{
		int i = Q.front(); cout<<i<<" "; Q.pop(); visited[i] = 1;

		for(int j=0; j<g[i].size(); j++)
		{
			if(!visited[g[i][j]]) Q.push(g[i][j]);
		}
	}
}

void display(vector<int> g[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("[%d]-->",i);

		for(int j=0; j<g[i].size(); j++) printf("[%d]-->",g[i][j]); cout<<"-->NULL\n";
	}
}

int main()
{
	int v,e; cin>>v>>e; vector<int> g[v];

	for(int i=0; i<e; i++)
	{
		int u,v; cin>>u>>v;	g[u].push_back(v); g[v].push_back(u);
	}

	display(g,v);

	bfs(g,v,0);

	return 0;
}