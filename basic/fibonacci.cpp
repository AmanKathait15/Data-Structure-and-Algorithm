#include<bits/stdc++.h>
using namespace std;

int fib[10001];

void build()
{
	fib[0]=fib[1]=0; fib[2]=1; 

	for(int i=3; i<10001; i++)
		fib[i] = fib[i-1]+fib[i-2];

}

int main()
{
	int t; cin>>t;

	build();

	while(t--)
	{
		cout<<"enter a number : ";

		int n,f=1; cin>>n; cout<<fib[n]<<"\n";
	}

	return 0;
}