#include<bits/stdc++.h>
using namespace std;

void pyramid(int n)
{
	for(int i=1; i<=n; i++)
	{
		int j = n-i; while(j--) cout<<" "; // spaces

		for(int j=0; j<2*i-1; j++)	cout<<"*";

		cout<<"\n";
	}
}

int main()
{
	int t; cout<<"enter number of test cases : "; cin>>t;

	while(t--)
	{
		int n; cout<<"\n enter size : "; cin>>n;

		system("clear"); 

		pyramid(n); 
	}

	return 0;
}