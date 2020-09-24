#include <bits/stdc++.h>
#define num unsigned long int
using namespace std;
#define n 4

void display(num a[][n+1])
{
    for(num i=1; i<=n; i++)
    {
        for(num j=1; j<=n; j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}

int main()
{
    num n,k,r,c,count=0;
    cin>>n>>k>>r>>c;

    bool a[n+1][n+1]={0};

    while(k--)
    {
        num x,y;
        cin>>x>>y;
        a[x][y]=1;
    }

    for(num i=c+1; i<=n; i++)
    if(a[r][c])     break;
    else
    {
    	
    }

    for(num i=c-1; i>0; i--)
    if(a[r][c])     break;
    else            count++;

    for(num i=r+1; i<=n; i++)
    if(a[r][c])     break;
    else            count++;

    for(num i=r-1; i>0; i--)
    if(a[r][c])     break;
    else            count++;

    for(num i=r+1,j=c+1; i<=n && j<=n; i++,j++)
    if(a[r][c])     break;
    else            count++;

    for(num i=r-1,j=c-1; i>0 && j>0; i--,j--)
    if(a[r][c])     break;
    else            count++;

    for(num i=r+1,j=c-1; i<=n && j>0; i++,j--)
    if(a[r][c])     break;
    else            count++;

    for(num i=r-1,j=c+1; i>0 && j<=n; i--,j++)
    if(a[r][c])     break;
    else            count++;


    cout<<count<<"\n";
    return 0;
}