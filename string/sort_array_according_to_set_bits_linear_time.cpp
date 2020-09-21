#include<bits/stdc++.h>
using namespace std;
#define num int

num countSetBits(num n)			// time complexity equal to number of set bits ex 100000001 2 iteration
{
	num c=0;

	while(n)
	{
		n = n & (n-1); c++;
	}

	return c;
}

int main()
{
	short t; cin>>t;

	while(t--)
	{
		num n; cin>>n; vector<num> count[32];	// intger are 32 bit 

		for(num i=0; i<n; i++)
		{
			num x; cin>>x;

			count[countSetBits(x)].push_back(x);
		}

		for(num i=31; i>0; i--)
		{
			for(num j=0; j<count[i].size(); j++) cout<<count[i][j]<<" ";
		}

		cout<<"\n";
	}

	return 0;
}