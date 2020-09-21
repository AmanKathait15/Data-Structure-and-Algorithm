#include <bits/stdc++.h> 
using namespace std;
#define num int 
#define f(i,v,n) for(num i=v; i<n; i++)

void sol(num a[], num n, num k) 
{
	deque<num> d; num i=0;

	for(i=0; i<k; i++)
	{
		while(!d.empty() and a[i]>=a[d.back()])	d.pop_back();

		d.push_back(i);
	}

	for(; i<n; i++)
	{
		//printf("(%d,%d) = %d\n",(i-k),i-1,a[d.front()]);

		cout<<a[d.front()]<<" ";

		while(!d.empty() and d.front()<=(i-k))	d.pop_front();

		while(!d.empty() and a[i]>=a[d.back()])	d.pop_back();

		d.push_back(i);
	}

	cout<<a[d.front()]<<"\n";
} 

int main() 
{ 
	num n,k; cin>>n>>k; num a[n]; 

	f(i,0,n) cin>>a[i];

	sol(a,n,k); 

	return 0; 
} 
