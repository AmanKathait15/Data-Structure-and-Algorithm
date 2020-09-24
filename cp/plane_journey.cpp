#include<bits/stdc++.h>
#define num long long int
using namespace std;

int main()
{
    num n,m;
    cin>>n>>m;

    vector<num> a(n),b(m),sum(m+1); sum[0]=0;

    for(num i=0; i<n; i++)
    cin>>a[i];
    for(num i=0; i<m; i++)
    cin>>b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(a[n-1]>b[m-1])
    {
        cout<<"-1\n"; return 0;
    }
    
    map<num,num> mp;

    num i=0,j=0,max=0,ind=0,summ=0;

    for(i=0; i<m; i++)
    {
        while(j<n && a[j]<=b[i])
        {
            mp[i]++; j++;
        }
        summ+=mp[i];
        if(mp[i]>max)
        {
            max=mp[i]; ind=i;
        }
        sum[i+1]+=summ;
    }
    /*cout<<max<<" "<<ind<<"\n";

    for(auto i=mp.begin(); i!=mp.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n";
    for(num i=0; i<=m; i++)
    {
        cout<<sum[i]<<" ";
    }*/

    num ans = ceil((sum[m]-sum[ind])/(float)(m-ind));
    //cout<<"\n"<<(sum[m]-sum[ind])<<" "<<(m-ind)<<" "<<tmp<<" ";
    ans = 2*ans-1;

    cout<<ans<<"\n";
    return 0;
}