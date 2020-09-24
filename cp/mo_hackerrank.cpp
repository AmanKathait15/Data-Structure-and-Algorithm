#include<bits/stdc++.h>
#define num long int
using namespace std;

num block;

struct Query 
{
    num l,r,ind;
    bool ans=0;
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

    num n,q;
    cin>>n; block = (num )sqrt(n);
    
    string str;
    cin>>str>>q;

    vector<Query> query(q);

    for(num i=0; i<q; i++)
    {
        cin>>query[i].l>>query[i].r; query[i].ind=i;
    }

    sort(query.begin(),query.end(),compare);    map<char,num> mp,ans;  

    num currL=query[0].l,currR = currL-1;

    for(num i=0; i<q; i++)
    {
        num L=query[i].l,R=query[i].r,ind=query[i].ind;

        while (currL < L) 
        { 
            mp[tolower(str[currL])]--;
            currL++; 
        } 
        while (currL > L) 
        {
            mp[tolower(str[currL-1])]++; 
            currL--;
        } 
        while (currR < R) 
        {
            currR++; 
            mp[tolower(str[currR])]++;
        } 
        while (currR > R) 
        { 
            mp[tolower(str[currR])]--; 
            currR--; 
        }

        for(auto j=mp.begin(); j!=mp.end(); j++)
        if(j->second)
        ans[ind]=(j->second);

        //printf("\n%d %d %d %d",L,R,ind,count);

        //for(auto j=mp.begin(); j!=mp.end(); j++)
        //   cout<<j->first<<" "<<j->second<<"\n"; cout<<"\n";
    }

    for(auto i=ans.begin(); i!=ans.end(); i++)
        cout<<i->second<<"\n";
    
    return 0;
}