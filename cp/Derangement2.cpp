#include<bits/stdc++.h>
#define num unsigned long int
using namespace std;

/*
Lexicographically smallest permutation with no digits at Original Index
Last Updated: 22-01-2019
Given an integer N. The task is to find the lexicographically smallest permutation of integer of the form: 12345…N such that no digit occurs at the index as in the original number, i.e. if P1P2P3…PN is our permutation then Pi must not be equal to i.
*/

string solve(int n)
{
	string str = "";

	if(n%2==0)
	{
		for(int i=1; i<=n; i++)
			if(i%2==0)
				str+=(i-1)+48;
			else
				str+=(i+1)+48;
	}
	else
	{

	}

	return str;
}

int main()
{
	num t; cin>>t;

	while(t--)
	{
		num n;	cin>>n;

		cout<<solve()<<"\n";
	}

	return 0;
}