#include<bits/stdc++.h>
using namespace std;
#define num int

void Sort(int a[], int n)
{
	int low = 0, mid = 0 , high = n-1;

	while(mid <= high)
	{
	    switch(a[mid])
	    {
	        case 0: swap(a[mid++],a[low++]); break;
	        case 1: mid++; break;
	        case 2: swap(a[mid],a[high--]); break;
	    }
	}
}

int main()
{
	num n; cin>>n; int a[n];

	for(num i=0; i<n; i++) cin>>a[i];

	Sort(a,n);		// sort in linear time with constant space

	for(num i=0; i<n; i++) cout<<a[i]<<" "; cout<<"\n";

	return 0;
}