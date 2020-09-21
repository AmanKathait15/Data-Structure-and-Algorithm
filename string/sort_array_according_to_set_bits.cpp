#include<bits/stdc++.h>
using namespace std;
#define num int

num countSetBits(num n)
{
	num c=0;

	while(n)
	{
		n = n & (n-1); c++;
	}

	return c;
}

bool compare(num x,num y)
{
	return countSetBits(x)>countSetBits(y);
}

int main()
{
	short t; cin>>t;

	while(t--)
	{
		num n; cin>>n; vector<num> a(n);

		for(num i=0; i<n; i++) cin>>a[i];

		sort(a.begin(),a.end(),compare);

		for(num i=0; i<n; i++) cout<<a[i]<<" "; cout<<"\n";
	}

	return 0;
}