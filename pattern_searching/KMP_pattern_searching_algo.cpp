#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

void LPS()
{
	
}

void KMP(string text,string pattern)
{
	int n = pattern.length() , m = text.length(); bool flag=0;

	int lps[m];

	LPS(pattern,)

}


int main()
{
	int t; cin>>t;

	while(t--)
	{
		string text,pattern; cin>>text>>pattern;

		KMP(text,pattern);
	}

	return 0;
}