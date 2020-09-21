//brute force approcah

#include<bits/stdc++.h>
using namespace std;
#define num long int

num sol(vector<num> a,num n,num sum)
{
    map<num,num> mp; num cur_sum=0;

    for(num i=0; i<n; i++)
    {
        cur_sum+=a[i];

        if (cur_sum == sum) 
        {
            mp[cur_sum]++;
            //cout << "Sum found between indexes "<< 0 << " to " << i << endl; return 1; 
        }  
        if (mp[cur_sum-sum]) 
        {
            mp[cur_sum]++;
        } 
  
        //mp[cur_sum] = i;
    }

    return mp[sum];
}

int main()
{
    int t; cin>>t; 

    while(t--)
    {
        num n,k; cin>>n;  vector<num> v(n);

        for(num i=0; i<n; i++) cin>>v[i]; cin>>k;

        cout<<sol(v,n,k)<<"\n";
    }

    return 0;
}