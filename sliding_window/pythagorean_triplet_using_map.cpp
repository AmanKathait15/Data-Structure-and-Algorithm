#include<bits/stdc++.h> 
using namespace std;
#define num long int 

num pythagorean_triplet(unordered_set<num> &mp)			// a^2 + b^2 = c^2
{
	for(auto i=mp.begin(); i!=mp.end(); )
	{
		auto a=i;	if(*a==0) continue; 		// if a is not persent in Hash i.e not persent in arr

		for(auto b=(++i); b!=mp.end(); b++)
		{
			num x  = *a, y = *b;

			if(y == 0 ) continue;

			num c = sqrt(x*x + y*y); 

			if((c*c) != (x*x + y*y))	continue; 	// not perfect square

			if(mp.find(c)!=mp.end())
			{
				/*printf("%d,%d,%d\n",x,y,c);*/ return 1;
			}
		}
	}

	return 0;
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		num n,x; cin>>n; unordered_set<num> mp;

		for(num i=0; i<n; i++)
		{
			cin>>x; mp.insert(x);
		}

		if(pythagorean_triplet(mp)) cout<<"Yes\n";
		else cout<<"No\n";
	}

	return 0; 
} 