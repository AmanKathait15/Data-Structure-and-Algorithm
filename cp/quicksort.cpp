#include<bits/stdc++.h>
#define num int
using namespace std;

void qs(num a[],num l,num u)
{
	if(l<u)
	{
		num i=l,j=u,key=a[l];

		while(i<=j)
		{
			while(key >= a[i] && i<=u) i++;
			while(key < a[j]) j--;

			
			if(i<j)
			{
				num tmp = a[i]; a[i]=a[j]; a[j]=tmp;
			}
		}
		
		a[l] = a[j];
		a[j] = key;

		qs(a,l,j-1);
		qs(a,j+1,u);
	}
}

int main()
{
	num t;

	//cout<<"enter number of test case : ";

	cin>>t; 

	while(t--)
	{
		num n;

		//cout<<"enter size of array : ";
		cin>>n;

		num a[n];

		//cout<<"enter array element : ";	
		for(num i=0; i<n; i++)
		cin>>a[i];

		qs(a,0,n-1);
		
		//cout<<"array after sorting : ";
		for(num i=0; i<n; i++)
		cout<<a[i]<<" ";

		cout<<"\n";
	}

	return 0;
}
