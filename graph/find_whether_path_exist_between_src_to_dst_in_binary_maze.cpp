#include<bits/stdc++.h>
using namespace std;
#define vect vector<vector<bool>>

//https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/

struct coord
{
	int x=0,y=0,d=0;
};

int Dx[] = {-1,1,0,0};
int Dy[] = {0,0,-1,1};

stack<pair<int,int>> path;

bool dfs(vect &graph,coord src,coord dst,int n,int m)
{
	graph[src.x][src.y]=0;

	cout<<src.x<<" "<<src.y<<"\n";	// print path

	path.push({src.x,src.y});

	if(src.x == dst.x and src.y==dst.y) return 1; 

	for(int i=0; i<4; i++)
	{
		coord tmp = src; tmp.x+=Dx[i]; tmp.y+=Dy[i];	int x=tmp.x,y=tmp.y;

		if(x>=0 and x<n and y>=0 and y<m and graph[x][y])
		if(dfs(graph,tmp,dst,n,m)) return 1;
	}

	path.pop();

	return 0;
}

bool check_path_exist(vect &graph,coord src,coord dst,int n,int m)
{
	if(graph[src.x][src.y]==0 || graph[dst.x][dst.y]==0) return 0;

	return dfs(graph,src,dst,n,m);
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

	swap(src,dst);	//  stack is used to print path 

	if(check_path_exist(graph,src,dst,n,m))
	{
		cout<<"path exist\n path : ";

		while(!path.empty()) 
		{
			pair<int,int> p = path.top();

			printf("(%d,%d)---",p.first,p.second); 

			path.pop();
		}
	}
	else 									cout<<"path not exist\n";

	
	return 0;
}