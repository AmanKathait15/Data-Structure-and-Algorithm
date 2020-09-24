#include<bits/stdc++.h>
#define num unsigned long int
using namespace std;

/*
Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
*/

// Bottom up approach

bool solve1(num arr[],num n,num i,num sum,num k)
{
	if(i>n && sum!=k)	return false;

	if(arr[i]==k || sum==k) return true;

	return (solve1(arr,n,i+1,sum+arr[i],k) || solve1(arr,n,i+1,sum,k));
}

// top down 

bool solve(num arr[],num i,num sum)
{
	if(sum == 0)	return true;

	if(i==0 && sum!=0) return false;

	if(arr[i]>sum)
		return solve(arr,i-1,sum);

	return (solve(arr,i-1,sum) || solve(arr,i-1,sum-arr[i]));
}



int main()
{
	num t; cin>>t;

	while(t--)
	{
		num n,k; cin>>n>>k;

		num arr[n+1];

		for(num i=1; i<=n; i++)	cin>>arr[i];

		//bool flag = solve(arr,n,1,0,k);

		cout<<solve(arr,n,k)<<" "<<solve1(arr,n,1,0,k)<<"\n";

	}

	return 0;
}