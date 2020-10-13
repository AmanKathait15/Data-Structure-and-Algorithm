#include<bits/stdc++.h>
using namespace std;

void rhombus(int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=i; j<n; j++) cout<<" ";

		for(int j=0; j<n; j++) cout<<"*"; cout<<"\n";
	}
}

int main()
{
	int t; cout<<"enter number of test cases : "; cin>>t;

	while(t--)
	{
		int n; cout<<"\n enter size : "; cin>>n;

		system("clear"); 

		rhombus(n); 
	}

	return 0;
}