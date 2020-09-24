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

    num n,s,mind=200,min,minf=200,posd,posf,pos;
    cin>>n>>s;

    num p[n]; bool a[n]; bool flag=1;

    for(num i=0; i<n; i++)
    {
        cin>>p[i]; 
        if(p[i]<minf)
        {
            min=p[i]; pos=i;
        }
    }
    for(num i=0; i<n; i++)
        cin>>a[i];
    if(a[pos]) minf=min;
    else mind = min;
    min = 200;
    if(a[pos])
    for(num i=0; i<n; i++)
    {
        if(a[i]==0 && p[i]<min)
            min=p[i];
    }
    else
    {
        for(num i=0; i<n; i++)
        {
        if(a[i] && p[i]<min)
            min=p[i];
        }
    }
    if(a[pos]) mind=min;
    else minf=min;

    if((s+mind+minf)>100)
        cout<<"no\n";
    else cout<<"yes\n";
    }
    return 0;
}