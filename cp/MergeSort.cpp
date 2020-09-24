#include<bits/stdc++.h>
#define num long int
using namespace std;

void merge(num arr[],num l,num m,num r)
{
	num n1 = m-l+1;
	num n2 = r-m;

	num a[n1],b[n2];

	for(num i=0; i<n1; i++)
		a[i] = arr[l+i];
	for(num j=0; j<n2; j++)
		b[j] = arr[m+1+j];

	num i=0,j=0,k=l;

	while(i<n1 && j<n2)
	{
		if(a[i]<b[j])
			arr[k++] = a[i++];
		else
			arr[k++] = b[j++];
	}

	while(i<n1)
		arr[k++] = a[i++];

	while(j<n2)
		arr[k++] = b[j++];
}


void mergesort(num arr[],num l,num r)
{
	if(l<r)
	{
		num mid = (l+r)/2;

		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
}

int main()
{
	num n; cin>>n;

	num a[n];

	for(num i=0; i<n; i++)
		cin>>a[i];

	mergesort(a,0,n-1);

	for(num i=0; i<n; i++)
		cout<<a[i]<<" ";

	return 0;
}