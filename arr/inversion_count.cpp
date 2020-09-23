#include<bits/stdc++.h>
using namespace std;
#define num int

int main()
{
    num t; cin>>t;

    while(t--)
    {
        num n; cin>>n; num a[n]; cin>>a[0];

        multiset<num> s; s.insert(a[0]); num c=0;
        
        for(num i=1; i<n; i++) 
        { 
            cin>>a[i];
            
            s.insert(a[i]); 
        
            auto it = s.upper_bound(a[i]); 

            num tmp = distance(it, s.end());  // worse case O(n) 

            printf("i:%d a[i]:%d tmp:%d\n",i,a[i],tmp);

            c+=tmp;
        }

        cout<<c<<"\n";
    }
    return 0;
}