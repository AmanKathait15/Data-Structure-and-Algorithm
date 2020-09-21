#include<bits/stdc++.h>
using namespace std;

int min_ins(string str,int l,int h)
{
	if(l>h) return INT_MAX; // so can not be come when use minimum
	if(l==h) return 0;
	if(l==h-1) return (str[l]==str[h])?0:1;

	if(str[l]==str[h])	return min_ins(str,l+1,h-1);
	else 			return min( min_ins(str,l,h-1), min_ins(str,l+1,h) ) + 1;
}

int main()
{
	int t; cin>>t;
	while(t--)
	{
		string str; cin>>str; cout<<min_ins(str,0,str.length()-1)<<"\n";
	}
	return 0;
}
