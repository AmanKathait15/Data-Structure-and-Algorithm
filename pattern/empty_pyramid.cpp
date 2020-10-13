#include<bits/stdc++.h>
using namespace std;

void pyramid(int n)
{
	for(int i=1; i<n; i++)
	{
		for(int j=i; j<n; j++) cout<<" "; // spaces

		for(int j=1; j<=2*i-1; j++)
		{
			if(j==1 or j==2*i-1) cout<<"*";
			else 				 cout<<" ";
		}

		cout<<"\n";
	}

	for(int i=0; i<2*n-1; i++) cout<<"*"; cout<<"\n";
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