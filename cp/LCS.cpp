// longest common subsequence np hard problem
#include <bits/stdc++.h>
using namespace std;
#define num unsigned long int 
#define max 5000

static num LCS[max][max]; string s1,s2,lcs="";

void setmatrix()
{
	for (num i = 0; i<max; ++i)
	{
		LCS[i][0]=0; LCS[0][i]=0;
	}
}

void findLCS(num n,num m)
{
	if(LCS[n][m]==0)
		return ;
	if(s1[n-1]==s2[m-1])
	{
		lcs+=s1[n-1]; n--; m--;
		findLCS(n,m);
	}
	else if(LCS[n][m-1]==LCS[n][m])
			findLCS(n,m-1);
	else	findLCS(n-1,m);
}

num setLCS(num n,num m)
{
	for (num i = 1; i<=n; ++i)
	{
		for (num j = 1; j <=m; ++j)
		{
			if(s1[i-1]==s2[j-1])
			{
				LCS[i][j]=LCS[i-1][j-1]+1;
			}
			else
			{
				num maximum = ((LCS[i-1][j]>LCS[i][j-1])?LCS[i-1][j]:LCS[i][j-1]);
				LCS[i][j] = maximum;
			}
		}
	}
	return LCS[n][m];
}

void display(num n,num m)
{
	for (num i = 0; i<=n; ++i)
	{
		for (num j = 0; j <=m; ++j)
		{
			cout<<LCS[i][j]<<" ";
		}	cout<<"\n";
	}
}

int main()
{
	setmatrix();
	cin>>s1>>s2;

	num n,m;
	if(s1.length()<s2.length())
	{
		n=s1.length(); m=s2.length();
	}else
	{
		n=s2.length(); m=s1.length();
		string tmp = s1; s1=s2; s2=tmp;
	}

	num l = setLCS(n,m);
	display(n,m);
	cout<<"length of longest common subsequence is "<<l<<"\n";
	//to find LCS
	findLCS(n,m);
	cout<<lcs<<" ";

	return 0;
}