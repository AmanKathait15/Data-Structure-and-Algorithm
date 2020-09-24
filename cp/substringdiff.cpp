// longest common subsequence np hard problem
#include <bits/stdc++.h>
using namespace std;
#define num long int 
#define max 1501

static num LCS[max][max],l=0,x,y,n,k,ans; string s1,s2;

void setmatrix()
{
	for (num i = 0; i<n; ++i)
	{
		LCS[i][0]=0; LCS[0][i]=0;
	}
}

void setLCS()
{
	for (num i = 1; i<=n; ++i)
	{
		for (num j = 1; j <=n; ++j)
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
}

void display()
{
	for (num i = 0; i<=n; ++i)
	{
		for (num j = 0; j <=n; ++j)
		{
			cout<<LCS[i][j]<<" ";
		}	cout<<"\n";
	}
}
num logic(num ans,num k)
{
	if(x==y)
		x=y=1;
	else if(x>y)
	{
		x-=y-1; y=1;
	}
	else
	{
		y-=x-1; x=1;
	}
	for (int i = x,j=y; i<=n && j<=n; i++,j++)
	{
		cout<<LCS[i][j]<<" ";
		num tmp = k,I=i,J=j,sum=0;
		while(tmp)
		{
			if(!LCS[I++][J++])	tmp--;
			sum++;
		}
		if(sum>ans)
			ans=sum;
	}
	return ans;
}

int main()
{
	short t;
	//cin>>t;

	//while(t--)
	//{
		cin>>k>>s1>>s2;

		n=s1.length(); ans=0;
		setmatrix();
		setLCS(); 	ans+=l; // l is length of common substring
		display();
		cout<<"\n";
		if(k==0)	ans=l;
		else if(l==0) ans=k;
		else
		{
			ans=logic(0,k);
		}

		cout<<"\n"<<ans<<"\n";
	//}

	return 0;
}