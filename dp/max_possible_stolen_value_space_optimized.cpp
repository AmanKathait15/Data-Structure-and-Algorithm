#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

int maxStole(int a[],int n)
{
	if(n<=0) return 0;	int v1,v2,ans;
	if(n==1) return a[0];
	if(n==2) return max(a[0],a[1]);

	v1=a[0],v2=max(a[0],a[1]);

	for(int i=2; i<n; i++)
	{
		ans = max(v2,v1+a[i]);
		
		v1 = v2;
		v2 = ans;
	}

	return ans;
}

int main()
{	
	int t; cin>>t;
	
	while(t--)
	{
	    int n; cin>>n; int a[n];
	    
	    for(int i=0; i<n; i++) cin>>a[i];
	    
	    cout<<maxStole(a,n)<<"\n";
	}
	
	return 0;
}