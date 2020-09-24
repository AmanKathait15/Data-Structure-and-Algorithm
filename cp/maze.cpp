#include <bits/stdc++.h>
#define num long int
using namespace std;

num maze[1000][1000]; string ans="";

void display(num n)
{
	for(num i=0; i<n; i++)
	{
		for(num j=0; j<n; j++)
		{
			cout<<maze[i][j]<<" ";
		}	cout<<"\n";
	}
}

void findpath(num n,num i,num j)
{
	if(i<n && j<n)
	{
		if(i==n-1 && j==n-1) return ;
		
		if(maze[i][j] && maze[i][j+1])
		{
			ans+="S"; i++;
			findpath(n,i,j);
		}
		else
		{
			ans+="E"; j++;
			findpath(n,i,j);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    num t;
    cin>>t;
    
    for(num it=1; it<=t; it++)
    {
        num n,l,i=0,j=0;
        cin>>n;

        string str;
        cin>>str; l=str.length();
        maze[0][0]=1;
        for(num k=0; k<l; k++)
        {
        	if(str[k]=='S') i++;
        	else j++;
        	maze[i][j]=1; 
        }
        display(n);
        findpath(n,0,0);
        cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}




