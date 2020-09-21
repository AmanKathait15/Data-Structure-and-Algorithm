#include<bits/stdc++.h> 
using namespace std;
#define num long int 

num trap_water(num a[],num n)
{
	num lhb[n]={0},rhb[n]={0},water_trap = 0; lhb[0]=a[0]; rhb[n-1]=a[n-1];

	for(num i=1; i<n; i++) lhb[i] = max(lhb[i-1],a[i]);
	for(num i=n-2; i>=0; i--) rhb[i] = max(rhb[i+1],a[i]);

	//for(num i=0; i<n; i++) cout<<lhb[i]<<" "; cout<<"\n";
	//for(num i=0; i<n; i++) cout<<rhb[i]<<" "; cout<<"\n";

	for(num i=1; i<n-1; i++)	water_trap += (min(lhb[i],rhb[i]) - a[i]);

	return water_trap;
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		num n; cin>>n; num a[n];

		for(num i=0; i<n; i++) cin>>a[i];

		cout<<trap_water(a,n)<<"\n";

	}
	return 0; 
} 