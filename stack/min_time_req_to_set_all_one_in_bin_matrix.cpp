#include<bits/stdc++.h>
using namespace std;
#define num int

void display(vector<vector<bool>> , num);

num solve(vector<vector<bool>> v, queue<pair<num,num>> Q, num n, num m, num zero)
{
	num time=0,ind=0;

	while(!Q.empty())
	{
		pair<num,num> p = Q.front(); Q.pop(); num i=p.first,j=p.second;

		if(i==-1 and j==-1)
		{
			time++; display(v,n);

			if(!Q.empty()) Q.push({-1,-1}); continue;
		}

		if(i+1<n and v[i+1][j]==0)
		{
			v[i+1][j]=1; Q.push({i+1,j}); zero--;
		}
		if(i-1>=0 and v[i-1][j]==0)
		{
			v[i-1][j]=1; Q.push({i-1,j}); zero--;
		}
		if(j+1<m and v[i][j+1]==0)
		{
			v[i][j+1]=1; Q.push({i,j+1}); zero--;
		}
		if(j-1>=0 and v[i][j-1]==0)
		{
			v[i][j-1]=1; Q.push({i,j-1}); zero--;
		}
		if(i+1<n and j+1<m and v[i+1][j+1]==0)
		{
			v[i+1][j+1]=1; Q.push({i+1,j+1}); zero--;
		}
		if(i-1>=0 and j-1>=0 and v[i-1][j-1]==0)
		{
			v[i-1][j-1]=1; Q.push({i-1,j-1}); zero--;
		}
		if(i+1<n and j-1>=0 and v[i+1][j-1]==0)
		{
			v[i+1][j-1]=1; Q.push({i+1,j-1}); zero--;
		}
		if(i-1>=0 and j+1<m and v[i-1][j+1]==0)
		{
			v[i-1][j+1]=1; Q.push({i-1,j+1}); zero--;
		} 

		cout<<(++ind)<<" ";
	}

	return zero?-1:time-1;
}

void display(vector<vector<bool>> v, num n)
{
	cout<<"\n";

	for(num i=0; i<n; i++)
	{
		for(num j=0; j<v[i].size(); j++)
		{
			cout<<v[i][j]<<" ";
		}	cout<<"\n";
	}
}


int main()
{
	num n,m,zero=0,x; cin>>n>>m; vector<vector<bool>> v(n); queue<pair<num,num>> Q;

	for(num i=0; i<n; i++)
	{
		for(num j=0; j<m; j++)
		{
			cin>>x; v[i].push_back(x);

			if(x==1) Q.push({i,j});
			else zero++;
		}
	}

	Q.push({-1,-1});

	cout<<solve(v,Q,n,m,zero)<<"\n";

	return 0;
}