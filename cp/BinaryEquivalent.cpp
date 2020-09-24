#include<bits/stdc++.h>
#define num long int
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);

	short n; cin>>n;

	num arr[n],ones[n]={0},max=0,sum=0,c=0;

	for(num i=0; i<n; i++)
	{
		cin>>arr[i]; if(arr[i]>max) max = arr[i];

		bitset<100000> b(arr[i]);

		ones[i] = b.count();
	}

	//for(num i=0; i<n; i++)
	//	cout<<ones[i]<<" ";

	max = int(log2(max)) + 1;

	//1
	for(num i=0; i<n; i++)
		if(ones[i]*2 == max)	c++;

	//2
	for(num i=0; i<n; i++)
	{
		
	}

	return 0;
}