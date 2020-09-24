#include<bits/stdc++.h>
#define num long int
using namespace std;

num block;

struct Query 
{
    num l,r,ind;
}; 

bool compare(Query q1,Query q2)
{
    if(q1.l/block != q2.l/block) 
        return q1.l/block < q2.l/block; 
    return q1.r < q2.r; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    num n,m,q;
    cin>>n>>m; block = (num)sqrt(n);

    vector<num> a(n),occ(m);

    for(num i=0; i<n; i++)
    cin>>a[i];
    for(num i=0; i<m; i++)
    cin>>occ[i];

    cin>>q;
    vector<Query> query(q);

    for(num i=0; i<q; i++)
    {
        Query tmp; num l,r; cin>>l>>r;
        tmp.l=l-1; tmp.r=r-1;
        tmp.ind = i;
        query[i] = tmp;
    }

    sort(query.begin(),query.end(),compare);
    
    map<num,num> mp,ans;

    num currL=query[0].l,currR = currL-1; //cout<<"\n";
    
    for(num i=0; i<q; i++)
    {
        num L=query[i].l,R=query[i].r;
       // cout<<L<<" "<<R<<"\n";
        
        while (currL < L) 
        { 
            mp[a[currL]]--;
            currL++; 
        } 
        while (currL > L) 
        {
            mp[a[currL-1]]++; 
            currL--;
        } 
        while (currR < R) 
        {
            currR++; 
            mp[a[currR]]++;
        } 
        while (currR > R) 
        { 
            mp[a[currR]]--; 
            currR--; 
        }

        //for(auto j=mp.begin(); j!=mp.end(); j++)
        //   cout<<j->first<<" "<<j->second<<"\n"; cout<<"\n";

        bool flag = 1;
        for(auto j=mp.begin(); j!=mp.end(); j++)
        {
            //cout<<j->first<<" "<<j->second<<"\n";
            //cout<<"case"<<i<<" "<<j->second<<":"<<occ[j->first-1]<<" ";
            if(j->second && j->second != occ[j->first-1])
            {
                flag = 0; break;
            }
        }
        if(flag)    ans[query[i].ind]=1; 
        else        ans[query[i].ind]=0;
    }
    for(auto j=ans.begin(); j!=ans.end(); j++)
        cout<<j->second<<"\n";
    return 0;
}