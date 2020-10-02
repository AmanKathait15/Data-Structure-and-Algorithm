#include<bits/stdc++.h>
using namespace std;
#define num long int

struct coord
{
	int x=0,y=0;
	int prod=1;
};

bool odd_divisor(num n)
{
	num x = sqrt(n);	//number of divisors is odd only in case of perfect squares

	return (x*x)==n?1:0;
}

int bfs(vector<vector<int>> &grid,int n,int m)
{
	coord src;	src.prod*=grid[0][0];	int path_count=0;

	queue<coord> Q; Q.push(src);

	while(!Q.empty())
	{
		src = Q.front(); Q.pop();

		if(src.x==n-1 and src.y==m-1 and odd_divisor(src.prod)) path_count++;
		
		if(src.x>=0 and src.x<n and src.y+1>=0 and src.y+1<m)
		{
			coord tmp = src; tmp.y++; tmp.prod*=grid[tmp.x][tmp.y]; Q.push(tmp);
		}
		if(src.x+1>=0 and src.x+1<n and src.y>=0 and src.y<m)
		{
			coord tmp = src; tmp.x++; tmp.prod*=grid[tmp.x][tmp.y]; Q.push(tmp);
		}
	}

	return path_count;
}

int main()
{
	num n,m; cin>>n>>m; vector<vector<int>> grid(n,vector<int>(m,0));

	for(num i=0; i<n; i++) for(num j=0; j<m; j++) cin>>grid[i][j];

	cout<<"number of path having odd number of divisors in thier path product : ";

	cout<<bfs(grid,n,m)<<"\n";

	return 0;
}
