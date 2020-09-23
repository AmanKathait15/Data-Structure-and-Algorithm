#include<bits/stdc++.h>
using namespace std;
#define num int

string rdwcs(string str,num n)
{
    string s=""; num counter = 0;   // 0000000000000000000000000000000 in binray

    for(num i=0; i<n; i++)
    {
        num x = str[i]-97; 

        if( (counter & ( 1 << x ) ) == 0)
        {
            s+=str[i]; counter = counter | (1 << x);
        }
    }  //cout<<counter<<" ";
    return s;
}

int main() 
{
  num t; cin>>t; t+=1;

  while(t--)
  {
     string str; getline(cin,str); cout<<rdwcs(str,str.length())<<"\n";
  }
  return 0; 
} 
