#include<bits/stdc++.h>
#define num long int
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    num t;
    cin>>t;

    while(t--)
    {
        num x,r,a,b;
        cin>>x>>r>>a>>b;

        num p = (2*r*(22)/7),d=p*x;

        cout<<p<<" "<<d;
        cout<<"\n";
    }

    return 0;
}