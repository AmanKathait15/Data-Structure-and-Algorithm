#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],bool visited[],int v,int i)
{
	if(!visited[i])
	{
		cout<<i<<" "; visited[i] = 1;
	}

	for(int j = 0; j<g[i].size(); j++)
	{
		if(!visited[g[i][j]])	dfs(g,visited,v,g[i][j]);
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

	bool visited[v]; memset(visited,0,sizeof(visited));

	dfs(g,visited,v,0);

	return 0;
}