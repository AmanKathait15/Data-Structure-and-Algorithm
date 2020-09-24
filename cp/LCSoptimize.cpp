// longest common subsequence np hard problem optimizing space complexity 



#include <bits/stdc++.h>
using namespace std;
#define num unsigned long int 
#define max 5001

static num LCS[2][max],length=0; string s1,s2,str="",lcs="";

void setmatrix(num m)
{
	LCS[0][0]=0; LCS[1][0]=0;
	for (num i = 0; i<=m; ++i)
	{
		LCS[0][i]=0;
	}
}
void swap(num m)
{
	for (num i = 0; i <=m; ++i)
	{
		LCS[0][i]=LCS[1][i];
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
				LCS[1][j]=LCS[0][j-1]+1;
				if(LCS[1][j]>length)
				{
					length++;
					str+=s1[i-1];
				}
			}
			else
			{
				num maximum = ((LCS[0][j]>LCS[1][j-1])?LCS[0][j]:LCS[1][j-1]);
				LCS[1][j] = maximum;
			}
		}
		swap(m);
	}
	return LCS[1][m];
}

void display(num n,num m)
{
	for (num i = 0; i<2; ++i)
	{
		for (num j = 0; j <=m; ++j)
		{
			cout<<LCS[i][j]<<" ";
		}	cout<<"\n";
	}
}

int main()
{
	cout<<"enter fisrt string : ";
	cin>>s1;
	cout<<"enter second string : ";
	cin>>s2;

	num n,m;
	if(s1.length()<s2.length())
	{
		n=s1.length(); m=s2.length();
	}else
	{
		n=s2.length(); m=s1.length();
		string tmp = s1; s1=s2; s2=tmp;
	}
	setmatrix(m);

	num l = setLCS(n,m);
	//display(n,m);
	cout<<"common subsequence is "<<str<<" of length "<<l<<"\n";

	return 0;
}