#include<bits/stdc++.h>
using namespace std;
#define num int

void sol(num a[], num n, num k)
{
	for(num i=0; i<n-k+1; i++)
	{
		num ans = a[i];

		for(num j=i; j<i+k; j++) ans = max(ans,a[j]);

		printf("(%d,%d) = %d\n",i,i+k-1,ans);
	}
}

int main()
{
	num n,k; cin>>n>>k; num a[n];

	for(num i=0; i<n; i++) cin>>a[i];

	sol(a,n,k);

	return 0;
}