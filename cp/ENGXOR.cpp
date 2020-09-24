#include <bits/stdc++.h>
using namespace std;
#define num unsigned int

int BitCount(unsigned int u)
{
     unsigned int uCount;

     uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

int main() {
	// your code goes here
	short t;
	cin>>t;
	while(1)
	{
		num n,p,count=0;
		cin>>n>>p;

		if(n==t)	break;
4 
		cout<<BitCount(n)<<" ";
		cout<<BitCount(p)<<" ";
		cout<<BitCount(n^p)<<"\n";
	}
	return 0;
}