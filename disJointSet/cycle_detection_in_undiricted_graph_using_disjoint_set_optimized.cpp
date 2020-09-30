#include<bits/stdc++.h>
using namespace std;
#define vect vector<vector<int>>

//https://www.geeksforgeeks.org/union-find/

//This method assumes that the graph doesn’t contain any self-loops.

int find(vect &subset,int i)
{
	int tmp = i;

	while(subset[i][0]!=i)
	{
		i = subset[i][0];
	}

	subset[tmp][0] = i; //path compression

	return i;
}

bool Union_by_rank(vect &subset,int x,int y)
{
	int  px=find(subset,x) , py = find(subset,y);

	// Attach smaller rank tree under root of high rank tree

	if(px==py) return 1;

	if(subset[px][1]>subset[py][1]) 		subset[py][0] = px;
	else if(subset[px][1]>subset[py][1])	subset[px][0] = py;
	else
	{
		subset[py][0] = px;	// If ranks are same, then make one as root and increment
		subset[py][1]++;
	}

	return 0;
}

int main()
{
	int V,E; cin>>V>>E; vect subset(V,vector<int>(2)); vector<pair<int,int>> edge_list;

	for(int i=0; i<V; i++) subset[i][0]=i , subset[i][1]=0;

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y; edge_list.push_back({x,y});
	}

	auto i=edge_list.begin();

	for(; i!=edge_list.end(); i++)
	{
		int x=i->first , y=i->second;

		//for(int i=0; i<V; i++) cout<<parent[i]<<" "; cout<<"\n";

		if(Union_by_rank(subset,x,y)) break;
	}

	if(i!=edge_list.end()) 		cout<<"contain cycle\n";
	else 						cout<<"not contain cycle \n";

	return 0;
}