#include <bits/stdc++.h> 
using namespace std; 
#define num int 

void bfs(vector<num> g[], num V,num i)
{
	queue<num> Queue; Queue.push(i); bool visited[V];

	while(!Queue.empty())
	{
		i = Queue.front(); Queue.pop();

		cout<<i<<" "; visited[i]=1;

		for(num j=0; j<g[i].size(); j++)
		{
			if(!visited[g[i][j]])
			{
				Queue.push(g[i][j]); visited[g[i][j]]=1;
			}
		}
	}
}

void display(vector<num> g[], num V)
{
	cout<<"adjaceny list : \n";

	for(num i=0; i<V; i++)
	{
		cout<<i<<": ";
		for(num j=0; j<g[i].size(); j++)
			cout<<g[i][j]<<" ";
		cout<<"\n";
	}
}

int main() 
{ 	
	num V,E,u,v; cin>>V>>E; vector<num> g[V];

	while(E--)
	{
		cin>>u>>v;	g[u].push_back(v);
	}

	display(g,V);

	for(num i=0; i<V; i++)
	{
		cout<<i<<": "; bfs(g,V,i); cout<<"\n";
	}
}