#include <bits/stdc++.h>
using namespace std;
#define num long long int

num date[401],overlap[401],c=2;

bool isleap(num i)
{
    if(i%400==0)    return true;
    if(i%4==0 && i%100!=0)  return true;
    return false;
}

void precomputation()
{
    for(num i=1; i<=400; i++)
    {
        date[i]=c;  overlap[i]=overlap[i-1];
        if(c==7 || (c==6 && !isleap(i))) overlap[i]=overlap[i-1]+1;
    
        if(isleap(i))
        {
            if(c==1) c=6;
            else if(c==2) c=7;
            else c-=2;
        }
        else if(c==1) c=7;
        else c--;
    }
    /*for (int i = 0; i <=400; ++i)
    {
        cout<<overlap[i]<<" ";
    }*/
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputation();

    num t;
    cin>>t;
    while(t--)
    {
        num m1,m2,y1,y2,ans=0;
        cin>>m1>>y1>>m2>>y2;

        m1>2?y1:y1--;
        m2<2?y2--:y2;

        ans += ((y2/400)-(y1/400))*overlap[400];
        ans += overlap[(y2%400)]-overlap[(y1%400)];
        cout<<ans<<"\n";
    }
    return 0;
}
