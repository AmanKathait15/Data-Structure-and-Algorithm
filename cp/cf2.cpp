#include<bits/stdc++.h>
using namespace std;
#define num long int

int main()
{
	num t;
	cin>>t;
	while(t--)
	{
		num n,a,b,i=0,j=0,k=0,c=0;
		cin>>n>>a>>b;

		string s=""; char ch = 'a';

		while(i<n)
		{
			while(j<a)
			{
				while(k<b)
				{
					s+=ch++;
					k++; j++; i++;
				}
				if(j<a)
				{s+=s[0]; j++; i++;}
			}
			if(i<n)
			{s+=s[c++]; i++;}
		}
		cout<<s<<"\n";
	}
	return 0;
}