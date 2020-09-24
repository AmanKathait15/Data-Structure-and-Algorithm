#include<bits/stdc++.h>
#define num int
using namespace std;

int main()
{
	num n; cin>>n;
	
	num a[n];
	
	for(num i=0; i<n; i++)
	cin>>a[i];
	
	num pos = 0,min ;
	
	for(num i=0; i<n; i++)
	{
		num min = a[i] , pos = i;
		for(num j=i; j<n; j++)
		{
			if(a[j]<min)
			{
				min = a[j]; pos = j;
			}
		}
		
		if(pos!=i)
		{
			num tmp = a[i]; a[i] = a[pos]; a[pos] = tmp;
		}
	}
	
	for(num i=0; i<n; i++)
	cout<<a[i]<<" ";
	
	return 0;
}
