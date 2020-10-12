#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l=0,r=0; cin>>n; float median,a;
    
    set<pair<float,float>> s; 

    cin>>a; s.insert({a,0}); median = a; printf("%0.1f\n",median);

    auto it=s.begin();

    for(int i=1; i<n; i++)
    {
        float a; cin>>a; s.insert({a,i});

        if(a<median)
        {
            l++;    if(l>r+1) { l--; r++; it--; median=it->first; }
        }
        else
        {
            r++;    if(r>l+1) { r--; l++; it++; median=it->first; }
        }
        
        //cout<<l<<" "<<r<<" ";
        
        if(l==r)    printf("%0.1f\n",median);
        
        else if(l>r)
        {
            it--; a=it->first; it++; printf("%0.1f\n",(median+a)/2.0);
        }
        else
        {
            it++; a=it->first; it--; printf("%0.1f\n",(median+a)/2.0);
        } 
    }
    return 0;
}
