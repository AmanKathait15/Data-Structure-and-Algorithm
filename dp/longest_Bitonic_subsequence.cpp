#include<bits/stdc++.h>
using namespace std;
#define num int

int lbs(int a[],int n)
{
	int lis[n],lds[n],lbs[n],m=0; lis[0]=1; lds[n-1]=1;

	for(num i=1; i<n; i++)
	{
		lis[i] = 1;

		for(num j=0; j<i; j++)
		{
			if(a[i]>a[j])	lis[i] = max(lis[i],lis[j]+1);
		}
	}

	for(num i=n-2; i>=0; i--)
	{
		lds[i] = 1;

		for(num j=n-1; j>i; j--)
		{
			if(a[i]>a[j])	lds[i] = max(lds[i],lds[j]+1);
		}
	}

	//for(num j=0; j<n; j++) cout<<lis[j]<<" "; cout<<"\n";
	//for(num j=0; j<n; j++) cout<<lds[j]<<" "; cout<<"\n";

	for(num i=0; i<n; i++)
	{
		lbs[i] = lis[i]+lds[i]-1; if(lbs[i]>m) m = lbs[i];
	}

	//for(num j=0; j<n; j++) cout<<lbs[j]<<" "; cout<<"\n";

	return m;
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		num n; cin>>n; num a[n]; 

		for(int i=0; i<n; i++) cin>>a[i];

		cout<<lbs(a,n)<<"\n";
	} 
	
	return 0; 
} 
