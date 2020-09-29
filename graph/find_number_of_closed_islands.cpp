#include<bits/stdc++.h>
using namespace std;
#define Vect vector<vector<int>>
#define display(i,j,n,m,a) for(int i=0; i<n; i++) { for(int j=0; j<m; j++) cout<<a[i][j]<<" "; cout<<"\n"; }

//https://www.geeksforgeeks.org/find-number-of-closed-islands-in-given-matrix/?ref=rp

/*A closed island is known as the group of 1s that is surrounded by only 0s on all the four sides (excluding diagonals). 
If any 1 is at the edges of the given matrix then it is not considered as the part of the connected island as it is not 
surrounded by all 0. */

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(Vect &graph,int i,int j,int n,int m)
{
	graph[i][j]=0;

	for(int k=0; k<8; k++)
	{
		int x = i+dx[k],y = j+dy[k];

		if(x>=0 and x<n and y>=0 and y<m and graph[x][y]==1)	dfs(graph,x,y,n,m);
	}
}

int main()
{
	int n,m,island_count=0; cin>>n>>m; vector<vector<int>> graph(n);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int x; cin>>x; graph[i].push_back(x);
		}
	}

	/*Perform DFS Traversal on all the corner of the given matrix and if any element has value 1 
	then marked all the cell with value 1 as visited because it cannot be counted in the resultant count.*/

	for(int i=0; i<n; i++) if(graph[i][0])   dfs(graph,i,0,n,m);  	//display(i,j,n,m,graph); cout<<"\n";
	for(int j=0; j<m; j++) if(graph[0][j])   dfs(graph,0,j,n,m);  	//display(i,j,n,m,graph); cout<<"\n";
	for(int i=0; i<n; i++) if(graph[i][m-1]) dfs(graph,i,m-1,n,m);	//display(i,j,n,m,graph); cout<<"\n";
	for(int j=0; j<m; j++) if(graph[n-1][j]) dfs(graph,n-1,j,n,m);	//display(i,j,n,m,graph); cout<<"\n";

	for(int i=1; i<n-1; i++)
	{
		for(int j=1; j<m-1; j++)
		if(graph[i][j])
		{
			island_count++; dfs(graph,i,j,n,m);
		}
	}

	cout<<island_count<<"\n";

	return 0;
}