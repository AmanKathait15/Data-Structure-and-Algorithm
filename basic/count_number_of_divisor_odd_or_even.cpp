#include<bits/stdc++.h>
using namespace std;
#define num long int

void brute_force(num n)
{
	num c = 2;	// 1 and the number itself

	for(num i=2; i<=sqrt(n); i++)
	{
		if(n%i==0) c += (n / i == i) ? 1 : 2;
	}

	cout<<c<<"\n";

	c%2==0?cout<<"even number of factors\n":cout<<"odd number of factors\n";
}

void optimized(num n)
{
	num x = sqrt(n);

	//number of divisors is odd only in case of perfect squares

	(x*x)!=n?cout<<"even number of factors\n":cout<<"odd number of factors\n";
}

int main()
{
	num t; cin>>t;

	while(t--)
	{
		num n; cin>>n;

		optimized(n);	 	// O(1)
		brute_force(n); 	// O(sqrt(n))
	}

	return 0;
}
