#include<bits/stdc++.h>
using namespace std;
#define num long int

int main()
{
	num t;
	cin>>t;
	while(t--)
	{
		string a[9];

		for(num i=0; i<9; i++)
		{
			cin>>a[i];
		}

		a[0][0] = (a[0][0]-48)%9+1+48;
		a[1][3] = (a[1][3]-48)%9+1+48;
		a[2][6] = (a[2][6]-48)%9+1+48;

		a[3][1] = (a[3][1]-48)%9+1+48;
		a[4][4] = (a[4][4]-48)%9+1+48;
		a[5][7] = (a[5][7]-48)%9+1+48;

		a[6][2] = (a[6][2]-48)%9+1+48;
		a[7][5] = (a[7][5]-48)%9+1+48;
		a[8][8] = (a[8][8]-48)%9+1+48;
		//cout<<"\n";
		for(num i=0; i<9; i++)
		{
			cout<<a[i]<<"\n";
		}
	}
	return 0;
}