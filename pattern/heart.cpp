#include<bits/stdc++.h>
using namespace std;

void heart(int n)
{
	for(int i=(n/2); i<n; i++)
	{
		for(int j=i; j<n; j++) 		cout<<" ";

		for(int j=0; j<2*i-1; j++) 	cout<<"*";

		for(int j=i; j<n; j++) 		cout<<" ";

		cout<<" ";

		for(int j=i; j<n; j++) 		cout<<" ";

		for(int j=0; j<2*i-1; j++) 	cout<<"*";

		for(int j=i; j<n; j++) 		cout<<" ";

		cout<<"\n";
	}

	for(int i=2*n; i>0; i--)
	{
		for(int j=i; j<2*n; j++) 	cout<<" ";

		for(int j=0; j<2*i-1; j++) 	cout<<"*";

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

		heart(n); 
	}

	return 0;
}