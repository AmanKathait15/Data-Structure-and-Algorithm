#include<bits/stdc++.h>
using namespace std;
#define vect vector<vector<bool>>

struct coord
{
	int x=0,y=0,d=0;
};

int Dx[] = {-1,1,0,0};
int Dy[] = {0,0,-1,1};

stack<pair<int,int>> path;

int shortest_path_length(vect &graph,coord src,coord dst,int n,int m)
{
	if(graph[src.x][src.y]==0 || graph[dst.x][dst.y]==0) return -1;

	queue<coord> Q; Q.push(src); graph[src.x][src.y]=0;

	if(src.x == dst.x and src.y == dst.y) return 0; src.d=1;

	while(!Q.empty())
	{
		src = Q.front(); Q.pop(); //cout<<src.x<<" "<<src.y<<"\n";

		for(int i=0; i<4; i++)
		{
			coord tmp = src; tmp.x+=Dx[i]; tmp.y+=Dy[i]; tmp.d++;

			if(tmp.x == dst.x and tmp.y == dst.y) return tmp.d;

			if(tmp.x>=0 and tmp.x<n and tmp.y>=0 and tmp.y<n and graph[tmp.x][tmp.y])
			{
				Q.push(tmp); graph[tmp.x][tmp.y]=0;
			}
		}

	} 

	return -1;
}

bool dfs(vect &graph,coord src,coord dst,int n,int m,int len)
{
	graph[src.x][src.y]=0;

	cout<<src.x<<" "<<src.y<<" "<<src.d<<"\n";	// print path

	path.push({src.x,src.y});

	if(src.x == dst.x and src.y==dst.y and src.d==dst.d) return 1;

	for(int i=0; i<4; i++)
	{
		coord tmp = src; tmp.x+=Dx[i]; tmp.y+=Dy[i];	int x=tmp.x,y=tmp.y; tmp.d++;

		if(x>=0 and x<n and y>=0 and y<m and graph[x][y] and tmp.d<=len)
		if(dfs(graph,tmp,dst,n,m,len)) return 1;
	}

	path.pop();

	return 0;
}

void print_shortest_path()
{
	cout<<"path exist\n path : ";

	while(!path.empty()) 
	{
		pair<int,int> p = path.top();

		printf("(%d,%d)---",p.first,p.second); 

		path.pop();
	}
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

	vect tmp = graph;

	int len = shortest_path_length(tmp,src,dst,n,m); src.d=len;

	if(len==-1)
	{
		cout<<"path not exist\n"; return 0;
	}

	//cout<<src.x<<" "<<src.y<<" "<<src.d<<"\n";
	//cout<<dst.x<<" "<<dst.y<<" "<<dst.d<<"\n";

	swap(src,dst); // path is stored in stack

	//cout<<src.x<<" "<<src.y<<" "<<src.d<<"\n";
	//cout<<dst.x<<" "<<dst.y<<" "<<dst.d<<"\n";

	cout<<"shortest_path_length : "<<len<<"\n";

	dfs(graph,src,dst,n,m,len);

	print_shortest_path();
	
	return 0;
}