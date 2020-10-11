#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/naive-algorithm-for-pattern-searching/

void naive_search(string text,string pattern)
{
	int pattern_length = pattern.length() , text_length = text.length(); bool flag=0;

	for(int i=0; i <= text_length - pattern_length; i++)
	{
		int j;

		for(j=0; j<pattern_length; j++)
		{
			if(text[j+i]!=pattern[j]) break;
		}

		if(j == pattern_length)
		{
			cout<<"pattern found at index "<<i<<"\n"; flag=1;
		}
	}

	if(!flag) cout<<"pattern not found in text \n";
}


int main()
{
	int t; cin>>t;

	while(t--)
	{
		string text,pattern; cin>>text>>pattern;

		naive_search(text,pattern);
	}

	return 0;
}