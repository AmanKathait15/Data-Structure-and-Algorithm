#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/count-possible-decodings-given-digit-sequence/

int count_total_ways_of_Decoding(string digits,int n)
{
	if(digits[0]=='0') return 0;

	int count[n+1]; count[0]=count[1]=1;

	for(int i=2; i<=n; i++)
	{
		count[i]=0;

		if(digits[i-1]>'0') count[i]=count[i-1];

		if(digits[i-2]=='1' or digits[i-2]=='2' and digits[i-1]<'7') count[i]+=count[i-2];

		cout<<count[i]<<" ";
	}

	return count[n];
}

int main()
{	
	int t; cin>>t;
	
	while(t--)
	{
		string digits; cin>>digits; cout<<count_total_ways_of_Decoding(digits,digits.length())<<"\n";
	}
	
	return 0;
}