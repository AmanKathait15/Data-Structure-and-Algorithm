#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		int j=i-1, tmp = a[i];

		while(j>=0 && a[j]>tmp)
		{
			a[j+1] = a[j]; j--;
		}

		a[j+1] = tmp;
	}
}

void display(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

int bs(int a[],int l ,int r , int key)
{
	if(l<=r)
	{
		int m = l + (r-l)/2; // to avoid overflow

		if(a[m]==key) return m;
		else if(key<a[m]) return bs(a,l,m-1,key);
		else return bs(a,m+1,r,key);
	}
	else return -1;
}

int main()
{
	int t; cin>>t;

	while(t--)
	{
		int n,key; cin>>n>>key; int a[n]; 

		for(int i=0; i<n; i++) cin>>a[i];

		insertion_sort(a,n);

		display(a,n);

		cout<<bs(a,0,n-1,key)<<"\n";
	}

	return 0;
}