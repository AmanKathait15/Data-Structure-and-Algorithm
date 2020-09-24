/*
this is an interview problem 
supoose 100 swordsmen are arrange in circle and they have badge from 1 t o 100 sowrdsmen 1 have sword and he kill next to it and pass to another 
he also do the same thing kill adjacent and pass this process repeat until only one swordsmen left you have to tell the badge bumber of that wordsmen
*/
#include<bits/stdc++.h>
using namespace std;
#define max 10000

int circle[max];

void setcicle(int n)
{
	for (int i = 1; i<=n; ++i)
	{
		circle[i]=i;
	}
}

void display(int n)
{
	for (int i = 1; i<=n; ++i)
	cout<<circle[i]<<" ";
	cout<<"\n";
}

int isempty(int n)
{
	for (int i = 1; i <=n; ++i)
	{
		if(circle[i])	return 0;
	}
	return 1;
}

int main()
{
	int n,m;	bool turn = false;
	cout<<"enter number of swordsmen : ";
	cin>>n; m=n;

	setcicle(n);
	//display(n);

	while(m)
	{
		for(int i=1; i<=n; i++)
		{
			if(circle[i])
			{
				if(turn)
					circle[i]=0;
				else
					cout<<circle[i]<<" ";
				turn=!turn;
			}
		}	cout<<"\n";
		m/=2;
	}

	return 0;
}