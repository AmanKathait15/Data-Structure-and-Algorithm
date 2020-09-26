#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/

struct coord
{
	int x,y;
	int d;
};

int min_steps_reach_knight(int n,coord k,coord t)
{
	bool visited[n][n]; memset(visited,0,sizeof(visited));

	int dx[] = {1,1,2,2,-1,-1,-2,-2};
	int dy[] = {2,-2,1,-1,2,-2,1,-1};

	queue<coord> Q; Q.push(k); 

	visited[k.x][k.y]=1;

	while(!Q.empty())
	{
		coord tmp = Q.front(); Q.pop();

		cout<<tmp.x<<" "<<tmp.y<<" "<<tmp.d<<"\n";

		if(tmp.x==t.x and tmp.y==t.y) return tmp.d;

		for(int i=0; i<8; i++)
		{
			coord c; c.x = tmp.x + dx[i] , c.y = tmp.y + dy[i] , c.d = tmp.d+1;

			if(c.x>=0 and c.x<n and c.y>=0 and c.y<n and visited[c.x][c.y]==0)
			{
				Q.push(c); visited[c.x][c.y]=1;
			}
		}
	}

	return -1;
}


int main()
{
	int n; cin>>n; coord k,t; cin>>k.x>>k.y>>t.x>>t.y; k.d=0;

	cout<<min_steps_reach_knight(n,k,t)<<"\n";

	return 0;
}