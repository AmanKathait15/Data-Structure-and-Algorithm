#include <bits/stdc++.h>
#define num long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    num t;
    cin>>t;
    
    for(num i=1; i<=t; i++)
    {
        string n,a="",b="";
        cin>>n;
        
        num l; bool flag=0;
        l=n.length();
        
        for(num i=0; i<l; i++)
        {
            if(n[i]=='4')
            { a+='3'; b+='1'; flag = 1;}
            else 
            {
                a+=n[i];
                if(flag) b+='0';
            }
        }
        
        cout<<"Case #"<<i<<": "<<a<<" "<<b<<"\n";
    }
    return 0;
}




