#include<bits/stdc++.h>
using namespace std;
#define num int

int main()
{
    num r,c,x,y;
    cin>>r>>c>>x>>y;

    num a[r][c];

    for(num i=0; i<r; i++)
    {
        for(num j=0; j<c; j++)
        {
            a[i][j] = max(abs(i-x),abs(j-y));

            cout<<a[i][j]<<" ";
        }   cout<<"\n";
    }

    return 0;
}