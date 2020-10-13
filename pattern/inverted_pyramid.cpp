#include<bits/stdc++.h>
using namespace std;

void inverted_pyramid(int n)
{
	for(int i=n; i>0; i--)
	{
		for(int j=i; j<n; j++)		cout<<" ";	// spaces

		for(int j=0; j<2*i-1; j++)  cout<<"*";	// stars

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

		inverted_pyramid(n); 
	}

	return 0;
}