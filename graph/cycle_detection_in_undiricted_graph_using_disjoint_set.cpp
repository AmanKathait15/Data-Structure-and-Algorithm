#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/union-find/

//This method assumes that the graph doesn’t contain any self-loops.

int find(int parent[],int i)
{
	int tmp = i;

	while(parent[i]!=-1)
	{
		i = parent[i];
	}

	//parent[tmp] = i; //path compression

	return i;
}

bool Union(int parent[],int x,int y)
{
	int  px=find(parent,x) , py = find(parent,y); 

	if(px != py) parent[px]=py;
	else return 1;

	return 0;
}

int main()
{
	int V,E; cin>>V>>E; vector<pair<int,int>> edge_list; int parent[V]; memset(parent,-1,sizeof(parent));

	//for(int i=0; i<V; i++) parent[i]=i;

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; edge_list.push_back({x,y});
	}

	auto i=edge_list.begin();

	for(; i!=edge_list.end(); i++)
	{
		int x=i->first , y=i->second;

		for(int i=0; i<V; i++) cout<<parent[i]<<" "; cout<<"\n";

		if(Union(parent,x,y)) break;
	}

	if(i!=edge_list.end()) 		cout<<"contain cycle\n";
	else 						cout<<"not contain cycle \n";

	return 0;
}