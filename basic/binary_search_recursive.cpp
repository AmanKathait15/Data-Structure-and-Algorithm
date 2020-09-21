#include<bits/stdc++.h>
using namespace std;

int bs(int a[],int l ,int r , int key)
{
	if(l<=r)
	{
		int m = l + (r-l)/2; // to avoid overflow

		if(a[m]==key) return m;
		else if(key<a[m]) return bs(a,l,m-1,key);
		else return bs(a,m+1,r,key);
	}
	else return -1;
}

int main()
{
	int t; cin>>t;

	while(t--)
	{
		int n,key; cin>>n>>key; int a[n]; 

		for(int i=0; i<n; i++) cin>>a[i]; sort(a,a+n);

		cout<<bs(a,0,n-1,key)<<"\n";
	}

	return 0;
}