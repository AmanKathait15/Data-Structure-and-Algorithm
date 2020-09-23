#include <bits/stdc++.h>
using namespace std;
#define num int

num minium_platform(num a[],num d[], num n)
{
	num m=0,p=0,i=0,j=0; sort(a,a+n); sort(d,d+n);

	for(num k=0; k<(n+n); k++)
	{
		if(a[i]<=d[j]) { i++; p++; }	// arrival 
		else 		   { j++; p--; } // deprature

		if(p>m) m=p;
	}

	return m;
}


int main() {
	//code

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t; cin>>t;
	
	while(t--)
	{
		num n; cin>>n; num a[n],d[n]; 
		
		for(num i=0; i<n; i++) cin>>a[i];
		for(num i=0; i<n; i++) cin>>d[i];
			
		cout<<minium_platform(a,d,n)<<"\n";
	}
	return 0;
}