// longest common subsequence np hard problem
#include <bits/stdc++.h>
using namespace std;
#define num unsigned long int 
#define max 100

static num LCS[max][max],l=0,x,y; string s1,s2,lcs="";

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
				if(LCS[i][j]>l)
				{
					l=LCS[i][j]; x=i; y=j;
				}
			}
			else LCS[i][j]=0;
		}
	}
	cout<<x<<" "<<y;
	return l;
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

	cout<<"length of longest common subsequence is "<<setLCS(n,m)<<"\n";
	display(n,m);
	//to find LCS
	//findLCS(n,m);
	//cout<<lcs<<" ";

	/*if(x==y)	x=y=0;
	else if(x>y)
	{
		x-=y; y=0;
	}else
	{
		y-=x; x=0;
	}*/

	//for (int i = x,j=y; i<=n && j<=m; i++,j++)
	//{
	//	cout<<LCS[i][j]<<" ";
	//}
	for (int i = x-l,j=y-l; i>0 && j>0; i--,j--)
	{
		cout<<LCS[i][j]<<" ";
	}
	return 0;
}