#include <bits/stdc++.h> 
using namespace std; 
#define num long int 

void printTwoElements(num arr[], num n,num S,num s) 
{
	num x,y; 

	for (num i = 1; i < n; i++) { 

		if (arr[abs(arr[i])] > 0) 
			arr[abs(arr[i])] = -arr[abs(arr[i])]; 
		else
			x = abs(arr[i]);
	}

	y = S-s+x;

	cout<<x<<" "<<y<<"\n"; 
} 

int main() 
{ 	
	num t; cin>>t;

	while(t--)
	{
		num n,s=0,S,x,y; cin>>n; num a[n+1]; S=n*(n+1)/2;

		for(num i=1; i<=n; i++)
		{
			cin>>a[i]; s+=a[i];
		}

		printTwoElements(a,n+1,S,s);
	} 
}