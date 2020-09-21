#include<bits/stdc++.h>
using namespace std;
#define num int
#define f(i,v,n) for(num i=v; i<n; i++)

void display(vector<vector<num>> a, num n, num m)
{
	cout<<"\n"; 

	f(i,0,n)
	{
		f(j,0,m) cout<<a[i][j]<<" "; cout<<"\n";
	}
}

int main(int argc, char const *argv[])
{
	num n,m; cin>>n>>m;	vector<vector<num>> arr(n,vector<num>(m)) , dp(n,vector<num>(m));

	f(i,0,n) f(j,0,m) cin>>arr[i][j];

	f(i,0,n) dp[i][0] = arr[i][0];

	display(dp,n,m);

	f(i,0,n) f(j,1,m) dp[i][j] += arr[i][j] + dp[i][j-1];		//row wise prefix sum

	display(dp,n,m);

	f(j,0,m) f(i,1,n) dp[i][j] += dp[i-1][j];		//col wise prefix sum

	display(dp,n,m); 

	num q; cin>>q;

	while(q--)
	{
		num r1,c1,r2,c2; cin>>r1>>c1>>r2>>c2;

		num res = dp[r2][c2]; 

		if (r1 > 0)       			res -= dp[r1-1][c2]; 
		if (c1 > 0)       			res -= dp[r2][c1-1]; 
		  
		if (r1 > 0 and c1 > 0)      res += dp[r1-1][c1-1];

		printf("M(%d,%d to %d,%d) = %d\n",r1,c1,r2,c2,res); 
	}

	return 0;
}