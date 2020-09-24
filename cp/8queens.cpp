#include<bits/stdc++.h>
using namespace std;
#define max 100

static int a[max][max];

void undo(int n,int value)
{
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j <n; ++j)
		{
			if(a[i][j]==value)	a[i][j]=0;
		}
	}
}

void setboard(int x,int y,int n,int value)
{
	int i=x,j=y;

	while(j<n)
		if(!a[i][j])
		a[i][j++]=value;
		else j++;
	i=x;j=y;
	while(i<n)
		if(!a[i][j])
		a[i++][j]=value;
		else i++;
	i=x;j=y;
	while(j>=0)
		if(!a[i][j])
		a[i][j--]=value;
		else j--;
	i=x;j=y;
	while(i>=0)
		if(!a[i][j])
		a[i--][j]=value;
		else i--;
	i=x;j=y;
	while(i<n && j<n)
		if(!a[i][j])
		a[i++][j++]=value;
		else	{i++;j++;}
	i=x;j=y;
	while(i>=0 && j>=0)
		if(!a[i][j])
		a[i--][j--]=value;
		else	{i--;j--;}
	i=x;j=y;
	while(i<n && j>=0)
		if(!a[i][j])
		a[i++][j--]=value;
		else	{i++;j--;}
	i=x;j=y;
	while(i>=0 && j<n)
		if(!a[i][j])
		a[i--][j++]=value;
		else	{i--;j++;}
}

void display(int n)
{
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j <n; ++j)
		{
			cout<<a[i][j]<<" ";
		}	cout<<"\n";
	}
}

int isfull(int n)
{
	for (int i = 0; i <n; ++i)
	{
		for (int j = 0; j <n; ++j)
		{
			if(a[i][j]==0)	return 0;
		}
	}
	return 1;
}

int main()
{
	int n,q=0,ch;
	cout<<"enter size of chessboard : ";
	cin>>n;

	while(1)
	{
		cout<<"1: insert 2: undo 3: clear 4: exit : ";
		cin>>ch;
		if(ch==4)	break;
		switch(ch)
		{
			case 1: int x,y;
					cout<<"enter position of queen "<<q+1<<": ";
					cin>>x>>y;

					if(x>=0 && x<n && y>=0 && y<n && !a[x][y])
					{
						setboard(x,y,n,++q);
						display(n);
					}
					else	cout<<"\n sorry queen can not be inserted at this position\n";
					break;
			case 2: if(q)
					undo(n,q--);
					display(n);
					break;
			case 3: system("clear"); break;
		}
	}
	return 0;
}