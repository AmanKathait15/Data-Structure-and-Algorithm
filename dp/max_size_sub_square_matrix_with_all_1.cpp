#include <bits/stdc++.h> 
using namespace std;
#define num int 
#define f(i,v,n) for(num i=v; i<n; i++)

void display(vector<vector<num>> v)
{
	cout<<"\n";
	
	f(i,0,v.size())
	{
		f(j,0,v[i].size())	cout<<v[i][j]<<" ";	cout<<"\n";
	}
}

int main() 
{ 
	num t; cin>>t; 

	while(t--)
	{
		num n,m,ans=0; cin>>n>>m; vector<vector<num>> a(n);

		f(i,0,n)
		f(j,0,m)
		{
			num x; cin>>x; a[i].push_back(x); ans=max(ans,x);
		}

		for(num i=1; i<n; i++)
		for(num j=1; j<m; j++)
		{
			if(a[i][j]==1) a[i][j] = min(a[i-1][j-1],min(a[i-1][j],a[i][j-1])) + 1;
			else		   a[i][j] = 0;
			
			ans = max(ans,a[i][j]);	
		}

		display(a);

		cout<<ans<<"\n";
	}

	return 0; 
} 
