#include<bits/stdc++.h> 
using namespace std;
#define num int

num substring_sum(string str)
{
	num n = str.length() , sum = 0 , mf = 1;

	for(num i=n-1; i>=0; i--)
	{
		num val = str[i] - '0';

		sum += val*(i+1)*mf;

		mf = mf * 10 + 1;
	}

	return sum;
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		string str; cin>>str; cout<<substring_sum(str)<<"\n";
	}

	return 0; 
} 