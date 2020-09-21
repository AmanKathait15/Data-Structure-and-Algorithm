#include<bits/stdc++.h> 
using namespace std;
#define num int 

num pythagorean_triplet(num arr[],num n,num max_ele)			// a^2 + b^2 = c^2
{
	num Hash[max_ele+1]={0};

	for(num i=0; i<n; i++) Hash[arr[i]]++;

	/*for(num i=0; i<max_ele; i++)
		cout<<Hash[i]<<" ";*/

	for(num a=1; a<max_ele+1; a++)
	{
		if(Hash[a]==0) continue; 		// if a is not persent in Hash i.e not persent in arr

		for(num b=a+1; b<max_ele+1; b++)
		{
			if(Hash[b]==0 || (a==b && Hash[a]==1)) continue;

			num c = sqrt(a*a + b*b); 

			if((c*c) != (a*a + b*b))	continue; 	// not perfect square

			if(c>max_ele) continue;

			if(Hash[c])
			{
				printf("%d,%d,%d\n",a,b,c); return 1;
			}
		}
	}

	return 0;
}

int main() 
{ 
	num n,max_ele=0; cin>>n; num a[n];

	for(num i=0; i<n; i++)
	{
		cin>>a[i]; if(a[i]>max_ele) max_ele=a[i];
	}

	cout<<pythagorean_triplet(a,n,max_ele)<<"\n";

	return 0; 
} 