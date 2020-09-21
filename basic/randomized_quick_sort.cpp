#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l , int h)
{
	int r = l + rand()%(h-l) , i=l-1; 

	swap(a[r],a[h]);

	for(int j=l; j<h; j++)
	{
		if(a[j]<a[h])	swap(a[++i],a[j]);
	}

	swap(a[++i],a[h]);

	return i;
}

void quick_sort(int a[], int l , int h)
{
	if(l<h)
	{
		int j = partition(a,l,h);

		quick_sort(a,l,j-1);
		quick_sort(a,j+1,h);
	}
}

void display(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

int main()
{
	int t; cin>>t;

	while(t--)
	{
		int n; cin>>n; int a[n]; 

		for(int i=0; i<n; i++) cin>>a[i];

		quick_sort(a,0,n-1);

		display(a,n);
	}

	return 0;
}