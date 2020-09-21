#include<bits/stdc++.h>
using namespace std;
#define num int

void display(vector<vector<num>> , num);

num solve(vector<vector<num>> v, num n, num m, num one)
{
	num ans=0;

	while(one)
	{
		set<pair<num,num>> Q; cout<<"one=="<<one<<"\n";

		for(num i=0; i<n; i++)
		{
			for(num j=0; j<m; j++)
			{
				if(v[i][j]==2)
				{
					if(i+1<n and v[i+1][j]==1)		Q.insert({i+1,j});
					if(i-1>=0 and v[i-1][j]==1)		Q.insert({i-1,j});
					if(j+1<m and v[i][j+1]==1)		Q.insert({i,j+1});
					if(j-1>=0 and v[i][j-1]==1)		Q.insert({i,j-1});
				}
			}
		}

		if(Q.empty()) break;

		for(auto p=Q.begin(); p!=Q.end(); p++)
		{
			//pair<num,num> p = Q.front(); Q.pop();

			v[p->first][p->second] = 2; one--;
		}

		display(v,n);	ans++;
	}

	return one?-1:ans;
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
	num n,m,one=0,x; cin>>n>>m; vector<vector<num>> v(n);

	for(num i=0; i<n; i++)
	{
		for(num j=0; j<m; j++)
		{
			cin>>x; if(x==1) one++; v[i].push_back(x);
		}
	}

	cout<<solve(v,n,m,one)<<"\n";

	return 0;
}