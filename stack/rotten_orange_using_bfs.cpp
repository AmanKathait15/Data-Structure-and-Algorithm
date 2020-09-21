#include<bits/stdc++.h>
using namespace std;
#define num int

void display(vector<vector<num>> , num);

num solve(vector<vector<num>> v, queue<pair<num,num>> Q, num n, num m, num one)
{
	num ans=0;

	while(!Q.empty())
	{
		pair<num,num> p = Q.front(); Q.pop(); num i=p.first,j=p.second;

		if(i==-1 and j==-1)
		{
			ans++; display(v,n);

			if(!Q.empty()) Q.push({-1,-1}); continue;
		}

		if(i+1<n and v[i+1][j]==1)
		{
			v[i+1][j]=2; Q.push({i+1,j}); one--;
		}
		if(i-1>=0 and v[i-1][j]==1)
		{
			v[i-1][j]=2; Q.push({i-1,j}); one--;
		}
		if(j+1<m and v[i][j+1]==1)
		{
			v[i][j+1]=2; Q.push({i,j+1}); one--;
		}
		if(j-1>=0 and v[i][j-1]==1)
		{
			v[i][j-1]=2; Q.push({i,j-1}); one--;
		} 
	}

	return one?-1:ans-1;
}

void display(vector<vector<num>> v, num n)
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
	num n,m,one=0,x; cin>>n>>m; vector<vector<num>> v(n); queue<pair<num,num>> Q;

	for(num i=0; i<n; i++)
	{
		for(num j=0; j<m; j++)
		{
			cin>>x; if(x==1) one++; v[i].push_back(x);

			if(x==2) Q.push({i,j});
		}
	}

	display(v,n);

	Q.push({-1,-1});

	cout<<solve(v,Q,n,m,one)<<"\n";

	return 0;
}