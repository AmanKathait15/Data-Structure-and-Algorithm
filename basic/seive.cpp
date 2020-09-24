#include<bits/stdc++.h>
using namespace std;
#define num long int
#define N 1000001

bitset<N> isprime;

void seive()
{
	isprime[0]=isprime[1]=1;

	for(num p=2; p<=sqrt(N); p++)
	{
		if(isprime[p]==0)
		{
			for(num j=p*p; j<=N; j+=p) isprime[j]=1;
		}
	}

	for(num i=0; i<N; i++) if(isprime[i]==0) cout<<i<<" ";
}

int main()
{
	seive();

	return 0;
}