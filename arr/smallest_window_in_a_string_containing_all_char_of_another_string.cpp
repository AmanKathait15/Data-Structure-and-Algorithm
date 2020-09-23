#include<bits/stdc++.h>
using namespace std;

string solve(string str, string text)
{
	int hash[26]={0} , n=str.length() , m = text.length() , beg = 0 , len = 0 ;

	// if(n<m) return "";

	for(int i=0; i<m; i++) hash[text[i]-'0']=1;

	for(int i=0; i<n; i++)
	{
		if(hash[str[i]-'0']==1)
		{
			hash[str[i]-'0']; beg=i;
		}
	}
}

int main() 
{ 
	short t; cin>>t;

	while(t--)
	{
		string str,text; cin>>str>>text;

		cout<<solve(str,text)<<"\n";
	} 
	
	return 0; 
} 
