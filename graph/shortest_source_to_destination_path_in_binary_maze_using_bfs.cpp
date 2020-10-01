#include<bits/stdc++.h>
using namespace std;
#define vect vector<vector<int>>

//https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

int Dx[] = {-1,1,0,0};
int Dy[] = {0,0,-1,1};

bool shortest_path(vect &graph,int sx,int sy,int dx,int dy,int n,int m)
{
	queue<pair<int,int>> Q; Q.push({sx,sy}); graph[sx][sy]=0;

	while(!Q.empty())
	{
		pair<int,int> p = Q.front(); Q.pop();

		for(int i=0; i<4; i++)
		{
			int x=p.first,y=p.second; x+=Dx[i]; y+=Dy[i];

			if(x==dx and y==dy) return 1;

			if(x>=0 and x<n and y>=0 and y<n and graph[x][y])
			{
				Q.push({x,y}); graph[x][y]=0;
			}
		}

	} 

	return 0;
}

int main()
{
	int n,m,sx,sy,dx,dy; vect graph(n,vector<int>(m)); cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>graph[i][j];
		}
	}

	cout<<"enter source and destination coordinate : \n";	cin>>sx>>sy>>dx>>dy;

	if(graph[sx][sy] and graph[dx][dy] and shortest_path(graph,sx,sy,dx,dy,n,m))
	{
		cout<<"path exist \n";
	}
	else
	{
		cout<<"path not exist \n";
	}

	return 0;
}