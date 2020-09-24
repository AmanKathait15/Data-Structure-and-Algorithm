#include<bits/stdc++.h>
#define num int
using namespace std;

int main()
{

	num n,f=1; 
	cout<<"enter number";
	cin>>n;
	
	for(int i=2; i<n; i++)
	f=f*i;
	
	cout<<f;
	return 0;
}
