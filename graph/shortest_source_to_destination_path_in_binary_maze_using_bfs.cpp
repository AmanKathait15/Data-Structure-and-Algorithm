#include<bits/stdc++.h>
using namespace std;
#define vect vector<vector<bool>>

//https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

struct coord
{
	int x=0,y=0,d=0;
};

int Dx[] = {-1,1,0,0};
int Dy[] = {0,0,-1,1};

int shortest_path(vect &graph,coord src,coord dst,int n,int m)
{
	if(graph[src.x][src.y]==0 || graph[dst.x][dst.y]==0) return -1;

	queue<coord> Q; Q.push(src); graph[src.x][src.y]=0;

	while(!Q.empty())
	{
		src = Q.front(); Q.pop(); //cout<<src.x<<" "<<src.y<<"\n";

		if(src.x == dst.x and src.y == dst.y) return src.d;

		for(int i=0; i<4; i++)
		{
			coord tmp = src; tmp.x+=Dx[i]; tmp.y+=Dy[i]; tmp.d++;

			if(tmp.x>=0 and tmp.x<n and tmp.y>=0 and tmp.y<n and graph[tmp.x][tmp.y])
			{
				Q.push(tmp); graph[tmp.x][tmp.y]=0;
			}
		}

	} 

	return -1;
}

int main()
{
	int n,m; cin>>n>>m; vect graph(n,vector<bool>(m)); coord src,dst;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int x; cin>>x; if(x) graph[i][j]=1; else graph[i][j]=0;
		}
	}
	
	cout<<"enter source and destination point : "; cin>>src.x>>src.y>>dst.x>>dst.y;

	int ans = shortest_path(graph,src,dst,n,m); cout<<ans<<"\n";
	
	return 0;
}