#include <bits/stdc++.h>
using namespace std;
#define foreach(n,m,a) for(int i=0; i<n; i++) for(int j=0; j<m; j++) cout<<a[i][j]<<" "
#define vect vector<vector<int>>
#define P pair<int,int>

// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm/0#

int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};

void bfs(vect &graph, int n,int m,int x,int y,int k)
{
    queue<P> Q; int val = graph[x][y];

    Q.push({x,y});

    while(!Q.empty())
    {
        P p = Q.front(); Q.pop(); graph[p.first][p.second] = k;

        for(int i=0; i<4; i++)
        {
            int x = p.first + dx[i] , y = p.second + dy[i];

            if(x>=0 and x<n and y>=0 and y<m and graph[x][y]!=k and graph[x][y]==val)
            {
                Q.push({x,y});
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin>>t;
    
    while(t--)
    {
        int n,m,x,y,k; cin>>n>>m;
        
        vect graph(n,vector<int>(m));
        
        for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        cin>>graph[i][j];
        
        cin>>x>>y>>k;

        bfs(graph,n,m,x,y,k);
        
        foreach(n,m,graph);

        cout<<"\n";
    }
    
	return 0;
}

/*
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9
*/