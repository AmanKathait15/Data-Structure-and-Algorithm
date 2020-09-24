#include <bits/stdc++.h> 
using namespace std;
#define num int

bool compare(string x,string y)
{
	string xy = x+y , yx = y+x;

	return (xy>yx)?1:0;
}

string largest(string s[],num n)
{
	string op="";

	sort(s,s+n,compare);

	for(num i=0; i<n; i++)
	{
		cout<<s[i]<<" "; op+=s[i];
	}	cout<<"\n";

	return op;
} 

int main() 
{ 
	num t; cin>>t;

	while(t--)
	{
		num n; cin>>n; string s[n];

		for(num i=0; i<n; i++) cin>>s[i];

		cout<<largest(s,n)<<"\n";
	}

	return 0; 
}