#include<bits/stdc++.h> 
using namespace std;
#define num int 

num lis(num a[], num n) 
{
	num l[n]; memset(l,1,sizeof(l));

	for(num i=1; i<n; i++)
	for(num j=0; j<i; j++)
	{
		if(a[i]>a[j]) l[i] = max(l[i],l[j]+1);
	}

	num *ptr = (num*)max_element(l,l+n);

	return *ptr;
} 

int main() 
{ 
	num n; cin>>n; num a[n];

	for(num i=0; i<n; i++) cin>>a[i];

	cout<<lis(a,n)<<"\n";

	return 0; 
} 
