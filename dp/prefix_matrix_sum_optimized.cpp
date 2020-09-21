#include<bits/stdc++.h>
using namespace std;
#define num int
#define f(i,v,n) for(num i=v; i<n; i++)
#define Vector vector<vector<num>>
#define print(r1,c1,r2,c2,res) printf("M(%d,%d to %d,%d) = %d\n",r1,c1,r2,c2,res)
#define input(r1,c1,r2,c2) scanf("%d%d%d%d",&r1,&c1,&r2,&c2)

void display(Vector a, num n, num m)
{
	cout<<"\n"; 

	f(i,0,n)
	{
		f(j,0,m) cout<<a[i][j]<<" "; cout<<"\n";
	}
}

int main(int argc, char const *argv[])
{
	num n,m; cin>>n>>m;	Vector dp(n,vector<num>(m));

	f(i,0,n) f(j,0,m) cin>>dp[i][j];

	f(i,0,n)
	{
		num sum = 0;

		f(j,0,m)
		{
			sum+= dp[i][j]; dp[i][j] = sum;	if(i>0) dp[i][j] += dp[i-1][j];
		} 
	}

	display(dp,n,m); num q; cin>>q;

	while(q--)
	{
		num r1,c1,r2,c2; input(r1,c1,r2,c2);

		num res = dp[r2][c2]; 

		if (r1 > 0)       			res -= dp[r1-1][c2]; 
		if (c1 > 0)       			res -= dp[r2][c1-1]; 
		  
		if (r1 > 0 and c1 > 0)      res += dp[r1-1][c1-1];

		print(r1,c1,r2,c2,res); 
	}

	return 0;
}