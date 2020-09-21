#include<bits/stdc++.h> 
using namespace std;
#define num int 

num trap_water(num a[],num n)
{
	num water_trap = 0 , lmax=0,rmax=0 , l=0,r=n-1;

	while(l<=r)
	{
		if(a[l]<a[r])
		{
			if(a[l]>lmax) lmax = a[l++];
			else water_trap += lmax - a[l++];

			printf("(%d,%d) lmax = %d \n",l,r,lmax);
		}
		else
		{
			if(a[r]>rmax) rmax = a[r--];
			else water_trap += rmax - a[r--];

			printf("(%d,%d) rmax = %d \n",l,r,rmax);
		}
	}

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