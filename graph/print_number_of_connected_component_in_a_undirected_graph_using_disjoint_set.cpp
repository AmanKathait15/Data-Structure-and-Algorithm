#include<bits/stdc++.h>
using namespace std;

struct disJointSet
{
	int parent;
	int rank;
};

int find(vector<disJointSet> &djs,int i)	// logn
{
	int tmp = i;

	while(djs[i].parent!=i)
	{
		i = djs[i].parent;
	}

	djs[tmp].parent = i;

	return i;
}

int Union_by_rank(vector<disJointSet> &djs,int x,int y,int &group)
{
	int px = find(djs,x) , py = find(djs,y);

	if(px==py) return 1;

	if(djs[px].rank > djs[py].rank) 		
	{ 
		djs[py].parent = px; 
		djs[px].rank+= djs[py].rank;
		djs[py].rank=0; 
	}
	else 	
	{ 
		djs[px].parent = py; 
		djs[py].rank+= djs[px].rank;
		djs[px].rank=0; 
	}

	group--; // on each union group size decrease by one

	return 0;
}

void display(vector<disJointSet> djs,int V)
{
	for(int i=0; i<V; i++) cout<<djs[i].parent<<" "; cout<<"\n";
	for(int i=0; i<V; i++) cout<<djs[i].rank<<" "; cout<<"\n";
}

int main()
{
	int V,E; cin>>V>>E; vector<disJointSet> djs(V); int group = V;

	for(int i=0; i<V; i++) djs[i].parent=i, djs[i].rank=1; // initialization

	for(int i=0; i<E; i++)
	{
		int x,y; cin>>x>>y;	Union_by_rank(djs,x,y,group); //display(djs,V);
	}

	//display(djs,V);

	printf("connected components in graph : %d\n",group);

	for(int i=0; i<V; i++) find(djs,i);	 // to update all parents value

	//display(djs,V);	map<int,vector<int>> mp;

	for(int i=0; i<V; i++)
	{
		if(djs[i].rank==0)	mp[djs[i].parent].push_back(i);
		else 				mp[i].push_back(i);
	}

	for(auto i=mp.begin(); i!=mp.end(); i++)
	{
		vector<int> v = i->second;

		for(auto j=v.begin(); j!=v.end(); j++) cout<<*j<<" "; cout<<"\n";
	}

	return 0;
}