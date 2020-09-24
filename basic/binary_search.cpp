#include <bits/stdc++.h> 
using namespace std; 
#define num long int 

/*num binary_search(num a[],num l,num r,num key)
{
	if(l<=r)
	{
		num mid = (l+r)/2;

		if(key == a[mid]) return mid+1;

		if(key>a[mid]) return binary_search(a,mid+1,r,key);
		else 		   return binary_search(a,l,mid-1,key);
	}
	
	return -1;
}*/

num binary_search(num a[],num l,num r,num key)
{
	while(l<=r)
	{
		num mid = l+(r-l)/2;

		if(key == a[mid]) return mid+1;

		if(key>a[mid]) l=mid+1;
		else 		   r=mid-1;
	}
	
	return -1;
}

int main() 
{ 	
	num t; cin>>t;

	while(t--)
	{
		num n,k; cin>>n; num a[n];

		for(num i=0; i<n; i++) cin>>a[i]; cin>>k;

		while(k)
		{
			cout<<k<<" "<<binary_search(a,0,n-1,k--)<<"\n";
		}
	} 
}