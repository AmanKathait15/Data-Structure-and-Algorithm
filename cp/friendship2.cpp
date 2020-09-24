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

    num parent[n+1],group[n+1]; group[0]=0; set<pair<num,num>> s;

    for(num i=1; i<=n; i++)
    {
        parent[i]=i; group[i]=1; s.insert({1,i});
    }

    while(m--)
    {
        num x,y,a,b,px,py;
        cin>>a>>b;

        x = min(a,b); y=max(a,b);

        px = find(parent,x); py = find(parent,y);

        if(px!=py)
        {
            if(px<py)
            {
                s.erase({group[px],px});
                group[px]+=group[py];       s.insert({group[px],px}); s.erase({group[py],py});
                parent[py]=px; g--; group[py]=0;
            }
            else
            {
                s.erase({group[py],py});
                group[py]+=group[px]; s.insert({group[py],py}); s.erase({group[px],px});
                parent[px]=py; g--; group[px]=0;
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
    cout<<"\n";
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        cout<<i->first<<" "<<i->second<<"\n";
    }
    return 0;
}