#include<bits/stdc++.h> 
using namespace std;

void convert(int n) 
{ 
    int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000},i=12; 
    
    string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
         
    while(n) 
    { 
      int div = n/number[i];

      n = n%number[i];

      while(div--) 
      { 
        cout<<symbol[i]; 
      }

      i--; 
    } 
} 
int main() 
{
    int t; cin>>t; 
    
    while(t--)
    {
        int n; cin>>n; convert(n);
    }

    return 0; 
} 