#include<bits/stdc++.h> 
using namespace std;
#define num int 

num pythagorean_triplet(num sq[],num n)			// a^2 + b^2 = c^2
{
	for(num c=n-1; c>1; c--)
	{
		num a=0,b=c-1;

		while(a<b)
		{
			if(sq[a]+sq[b] == sq[c]) 
			{
				printf("%d,%d,%d\n",sq[a],sq[b],sq[c]);	return 1;
			}
			else (sq[a]+sq[b]<sq[c])?a++:b--;
		}
	}

	return 0;
}

int main() 
{ 
	num n; cin>>n; num a[n],sq[n];

	for(num i=0; i<n; i++) 
	{
		cin>>a[i]; sq[i] = a[i]*a[i];
	}

	sort(sq,sq+n);

	cout<<pythagorean_triplet(sq,n)<<"\n";

	return 0; 
} 