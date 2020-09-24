#include<bits/stdc++.h>
#define num long int
using namespace std;

num find(num parent[],num i)
{
    num j=i;
    while(i!=parent[i])
    {
        i=parent[i];
    }
    parent[j]=i;
    return i;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    num n,m,g;
    cin>>n>>m;  g=n;

    num parent[n+1],group[n+1];

    for(num i=1; i<=n; i++)
    {
        parent[i]=i; group[i]=1;
    }

    while(m--)
    {
        num x,y,a,b,px,py;
        cin>>a>>b;

        x = min(a,b); y=max(a,b);

        px = find(parent,x); py = find(parent,y);

        if(px!=py)
        {
            if(group[px]>group[py])
            {
                group[px]+=group[py]; parent[py]=px; g--; group[py]=0;
            }
            else
            {
                group[py]+=group[px]; parent[px]=py; g--; group[px]=0;
            }
        }
    }

    cout<<g<<"\n";

    for(num i=1; i<=n; i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<"\n";
    for(num i=1; i<=n; i++)
    {
        cout<<group[i]<<" ";
    }

    sort(group,group+n+1);
    
    for(num i=1; i<=n; i++)
    {
        if(group[i])
        cout<<group[i]<<" ";
    }
    return 0;
}