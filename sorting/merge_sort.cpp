#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l , int m, int h)
{
	int n1 = m-l+1 , n2 = h-m , a[n1],b[n2];

	for(int i=0; i<n1; i++)	a[i] = arr[i+l];

	for(int i=0; i<n2; i++) b[i] = arr[i+m+1];

	int i=0,j=0,k=l;

	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])	arr[k++] = a[i++];
		else 			arr[k++] = b[j++];
	}

	while(i<n1) arr[k++] = a[i++];

	while(j<n2) arr[k++] = b[j++];
}

void merge_sort(int a[], int l , int h)
{
	if(l<h)
	{
		int m = l + (h-l)/2;

		merge_sort(a,l,m);
		merge_sort(a,m+1,h);

		merge(a,l,m,h);
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

		merge_sort(a,0,n-1);

		display(a,n);
	}

	return 0;
}