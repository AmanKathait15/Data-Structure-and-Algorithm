#include<bits/stdc++.h>
using namespace std;
#define num int

void rdwcs(string str,num n)
{
    string s="";  bitset<256> b;

    for(num i=0; i<n; i++)
    {
        num x = str[i]; 

        if(b[x]==0)
        {
            s+=str[i]; b[x]=1;
        }
    }

    //cout<<b<<" ";
    cout<<s;
}

int main() 
{
  num n,t; cin>>t; n=t+1;

  while(n--)
  {
     string str; getline(cin,str); rdwcs(str,str.length());
     if(n!=t) cout<<"\n";
  }
  return 0; 
} 
