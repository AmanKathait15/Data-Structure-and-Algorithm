#include<bits/stdc++.h>
#define num long int
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    num n,empty,move=0,i,j;
    cin>>n;

    num a[n+1]; empty=n; a[n]=-1;

    for(i=0; i<n; i++)  cin>>a[i];

    for(i=0; i<n; i++)
    {
        if(i!=a[i])
        {
            for(j=i+1; j<=n; j++)
            if(a[j]==i) break;

            if(a[i]==-1)
            {
                move+=1; a[i]=i; cout<<"+1 ";
            }
            else
            {
                move+=2; a[empty]=a[i]; a[i]=i; cout<<"+2 ";
            }
            a[j]=-1; empty=j;
            cout<<empty<<"\n";
        }
        else cout<<"+0\n";
        //cout<<a[i]<<" ";
    }
    cout<<move<<"\n";
    return 0;
}