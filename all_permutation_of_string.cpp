#include<bits/stdc++.h>
using namespace std;

void permutation(string str)
{
  do
  {
    cout<<str<<" ";
  } while(next_permutation(str.begin(),str.end()));
}

int main()
{
    int t; cin>>t;

    while(t--)
    {
        string str; cin>>str;

        sort(str.begin(),str.end());

        permutation(str); cout<<"\n";
    }
    return 0;
}