#include <bits/stdc++.h>
using namespace std;
#define num long int

static num lps[5000][5000];

num LPS(string str, num n)
{
	for(num i=0; i<n; i++)
		lps[i][i]=1;

	for(num k=1; k<n; k++)
	{
		for(num i=0; i<n-k; i++)
		{
			num j=i+k;

			if(str[i]==str[j])
			{
				lps[i][j] = 2 + lps[i+1][j-1];
			}
			else lps[i][j] = max(lps[i][j-1],lps[i+1][j]);
		}
	}

	return lps[0][n-1];
}

string backtrack(bool a[],string str,num n)
{
	num i=0,j=n-1,l; string ans = "";

	while(i<=j)
	{
		if(lps[i][j] == lps[i+1][j])
		{
			i+=1;
		}
		else if(lps[i][j] == lps[i][j-1])
		{
			j-=1;
		}
		else
		{
			a[i]=1; a[j]=1; i+=1; j-=1;
		}
	}

	for(num i=0; i<n; i++)
		if(a[i]) ans+=str[i];

	return ans;
}

int main() {
   
    num t;
    cin>>t;

    while(t--)
    {
    	num n;
    	cin>>n; bool a[n]={0};

    	string str;
    	cin>>str;

    	cout<<LPS(str,n)<<"\n";
    	cout<<backtrack(a,str,n)<<"\n";
    }
    return 0;
}