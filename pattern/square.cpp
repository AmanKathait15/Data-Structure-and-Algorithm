#include<bits/stdc++.h>
using namespace std;

void square(int n)
{
	for(int i=0; i<n; i++)
	{
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

		square(n); 
	}

	return 0;
}