#include<bits/stdc++.h>
using namespace std;
#define num long int

int numberOfPaths(int m, int n) 	//https://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
{ 
    int path_count = 1; 

    for (int i = n; i < (m + n - 1); i++)
    {
    	path_count *= i; 
        path_count /= (i - n + 1); 
    } 

    return path_count; 
} 

int bfs(vector<vector<int>> &grid,int n,int m)
{
	queue<pair<int,int>> Q; Q.push({0,0}); int path_count=0;

	while(!Q.empty())
	{
		pair<int,int> p = Q.front(); Q.pop();

		if(p.first==n-1 and p.second==m-1)	path_count++;
		
		if(p.first>=0 and p.first<n and p.second+1>=0 and p.second+1<m) Q.push({p.first,p.second+1});	// right
		if(p.first+1>=0 and p.first+1<n and p.second>=0 and p.second<m) Q.push({p.first+1,p.second});	// down
	}

	return path_count;
}

int main()
{
	num n,m; cin>>n>>m; vector<vector<int>> grid(n,vector<int>(m,1));

	//for(num i=0; i<n; i++) for(num j=0; j<m; j++) cin>>grid[i][j];

	cout<<bfs(grid,n,m)<<"\n";
	cout<<numberOfPaths(n,m)<<"\n";

	return 0;
}
