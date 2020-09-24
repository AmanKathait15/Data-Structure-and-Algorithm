#include<bits/stdc++.h>
#define num unsigned long int
using namespace std;
#define max 10000000
#define mod 1000000007

/*
A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.

Given a number n, find total number of Derangements of a set of n elements.

You are given N balls numbered from 1 to N and there are N baskets numbered from 1 to N in front of you, the ‘i’th basket is meant for the ‘i’th ball. The task is to calculate the number of ways in which none of the balls goes into their respective basket.

Input: The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of a single line containing an integer N.

Output: Corresponding to each test case, print the desired output in a new line. Since the answer can be large, print it modulo 109 + 7.
*/

num dp[max+1] ;

void derangement()
{
	dp[0]=dp[1]=0;
	dp[2]=1;

	for(int i=3; i<=max; i++)
		dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
}

int main()
{
	num t; cin>>t;

	derangement();

	while(t--)
	{
		num n; cin>>n;

		cout<<dp[n]%mod<<"\n";
	}

	return 0;
}