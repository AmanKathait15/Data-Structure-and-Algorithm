#include<bits/stdc++.h>
#define num int
using namespace std;

/*
In mathematics, the Golomb sequence is a non-decreasing integer sequence where n-th term is equal to number of times n appears in the sequence.

The first few values are
1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, ……

Explanation of few terms:
Third term is 2, note that three appears 2 times.
Second term is 2, note that two appears 2 times.
Fourth term is 3, note that four appears 3 times.

Given a positive integer n. The task is to find the first n terms of Golomb sequence.

Examples :

Input : n = 4
Output : 1 2 2 3

Input : n = 6
Output : 1 2 2 3 3 4
*/

num dp[100];

num golomb(num n)
{
	if(n==1) return 1;

	return (1 + golomb(n - golomb(golomb(n-1))));
}

void DP()
{

	dp[1]=1;

	for(num i=2; i<100; i++)
	{
		dp[i] = (1 + dp[i - dp[dp[i-1]]]);
	}
}


int main()
{
	num t; cin>>t;

	DP();

	for(num i=1; i<t; i++)
	{
		cout<<golomb(i)<<" "<<dp[i]<<"\n";
	}

	return 0;
}