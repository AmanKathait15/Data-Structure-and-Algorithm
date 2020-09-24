#include<bits/stdc++.h>
#define num unsigned long int
using namespace std;

/*
A Derangement is a permutation of n elements, such that no element appears in its original position. For example, a derangement of {0, 1, 2, 3} is {2, 3, 1, 0}.

Given a number n, find total number of Derangements of a set of n elements.
*/

num derangement(num n)
{
	if(n<=1) return 0;
	if(n==2) return 1;

	return (n-1)*(derangement(n-1)+derangement(n-2));
}

int main()
{
	num t; cin>>t;

	while(t--)
	{
		num n; cin>>n;

		cout<<derangement(n)<<"\n";
	}

	return 0;
}