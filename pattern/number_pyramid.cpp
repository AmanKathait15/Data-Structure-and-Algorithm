#include<bits/stdc++.h>
using namespace std;

void pyramid(int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<n; j++) cout<<" "; // spaces

		for(int j=i; j<2*i; j++)	cout<<j;

		for(int j=2*i-2; j>=i; j--)	cout<<j;

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