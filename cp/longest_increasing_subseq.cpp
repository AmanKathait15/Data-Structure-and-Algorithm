// longest incresing subsequence
// ex 1 0 2 -1 3 4 8 5 7 6
// ans { 1 2 3 4 5 6 } of length 6

#include <bits/stdc++.h>
using namespace std;
#define num unsigned long int 

num lis(num LIS[], num a[], num n)
{
	num max = 1;
	for (num i = 1; i < n; ++i)
	{
		for (num j = 0; j < i; ++j)
		{
			if(a[i]>a[j])
				LIS[i] = max(LIS[i] , LIS[j] + 1);
		}
		if(LIS[1]>max)	max=LIS[i];
	}
	
	for (num i = 0; i < n; ++i)
		cout<<LIS[i]<<" ";
	return max;
}

int main()
{
	num n;
	cin>>n;
	num a[n],LIS[n];

	for(num i=0; i<n; i++)
	{
		cin>>a[i];	LIS[i]=1;
	}
	num ans = lis(LIS,a,n);
	cout<<"\nlength of longest incresing subsequence is "<<ans;
	return 0;
}