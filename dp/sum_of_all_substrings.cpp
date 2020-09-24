#include<bits/stdc++.h> 
using namespace std;
#define num int

num substring_sum(string str)
{
	num n = str.length() , s[n] , sum = str[0] - '0' , prev = sum;

	for(num i=1; i<n; i++)
	{
		num val = str[i] - '0';

		//printf("s[%d] = (%d * %d) + (%d * %d) \n",i,i+1,val,10,prev);

		prev = (i+1) * val + 10 * prev; 

		sum += prev;
	}

	return sum;
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		string str; cin>>str; cout<<substring_sum(str)<<"\n";
	}

	return 0; 
} 