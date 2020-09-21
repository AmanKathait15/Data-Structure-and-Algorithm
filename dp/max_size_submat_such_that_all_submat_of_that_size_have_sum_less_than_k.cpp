//https://www.geeksforgeeks.org/maximum-size-of-square-such-that-all-submatrices-of-that-size-have-sum-less-than-k/?ref=rp

#include<bits/stdc++.h>
using namespace std;
#define num int
#define f(i,v,n) for(num i=v; i<n; i++)
#define Vector vector<vector<num>>

void display(Vector a, num n, num m)
{
	cout<<"\n"; 

	f(i,0,n)
	{
		f(j,0,m) cout<<a[i][j]<<" "; cout<<"\n";
	}
}

void build_prefix_sum_mat(Vector arr,Vector &dp,num n,num m)
{
	f(i,0,n)
	{
		num sum = 0;

		f(j,0,m)
		{
			sum+= arr[i][j]; dp[i][j] = sum;	if(i>0) dp[i][j] += dp[i-1][j];
		} 
	}
}

num sum_of_subMat(Vector dp,num r1,num c1,num r2,num c2)
{
	num sum = dp[r2][c2]; 

	if (r1 > 0)       			sum -= dp[r1-1][c2]; 
	if (c1 > 0)       			sum -= dp[r2][c1-1]; 
	  
	if (r1 > 0 and c1 > 0)      sum += dp[r1-1][c1-1];

	return sum;
}

bool check(Vector dp,num size,num n,num m,num k)
{
	for(num i=0; i<n; i++)
	
	for(num j=0; j<m; j++)
	
	if(i+size-1<n and j+size-1<m)
		
	if(sum_of_subMat(dp,i,j,i+size-1,j+size-1) > k)		return 0;

	return 1;
}

num max_subsq_size(Vector dp,num n,num m,num k)
{
	for(num s=min(n,m); s>0; s--)	if(check(dp,s,n,m,k)) 	return s;

	return 0;
}

int main(int argc, char const *argv[])
{
	num n,m,k; cin>>n>>m>>k;	Vector a(n,vector<num>(m)) , dp(n,vector<num>(m));

	f(i,0,n) f(j,0,m) cin>>a[i][j];

	build_prefix_sum_mat(a,dp,n,m);

	display(dp,n,m); 

	cout<<max_subsq_size(dp,n,m,k)<<"\n";

	return 0;
}