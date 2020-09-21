#include <bits/stdc++.h> 
using namespace std;
#define num int
num piviot(num a[], num n)
{
	num lmax[n],rmin[n]; lmax[0]=a[0]; rmin[n-1]=a[n-1];

	for(num i=1; i<n; i++)
		lmax[i] = max(lmax[i-1],a[i]);

	for(num i=n-2; i>=0; i--)
		rmin[i] = min(rmin[i+1],a[i]);

	//for(num i=0; i<n; i++)	cout<<lmax[i]<<" "; cout<<"\n";

	//for(num i=0; i<n; i++)	cout<<rmin[i]<<" "; cout<<"\n";

	for(num i=1; i<n-1; i++)
		if(a[i]>=lmax[i-1] && a[i]<=rmin[i+1]) return a[i];

	return -1;
}

int main() 
{ 
	num t; cin>>t;

	while(t--)
	{
		num n; cin>>n; num a[n];

		for(num i=0; i<n; i++) cin>>a[i];

		cout<<piviot(a,n)<<"\n";
	}

	return 0; 
}