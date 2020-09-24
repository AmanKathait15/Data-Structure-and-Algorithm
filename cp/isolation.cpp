#include <bits/stdc++.h>
#define num long long int 
using namespace std;

int main() {
    // your code goes here
    num t;
    cin>>t;
    
    while(t--)
    {
        num n,q;
        cin>>n>>q; 
        num freq[26]={0};

        string str; cin>>str;          //n=str.length();

        for(num i=0; i<n; i++)
        {
            freq[str[i]-97]++;
        }

        for(num i=0; i<26; i++)
        {
            if(freq[i])
            cout<<char(i+97)<<" : "<<freq[i]<<"\n";
        }

        sort(freq,freq+26,greater<int>()); 
        num m = freq[0];

        while(q--)
        {
            num c,count=0;
            cin>>c;

            if(c>=m)
            {
                cout<<"0\n"; continue;
            }
            if(c==0)
            {
                cout<<n<<"\n"; continue;
            }

            for(num i=0; i<26; i++)
            {
                if(freq[i]>c)
                {
                    count+= freq[i]-c;
                }
            }

            cout<<count<<"\n";
        }
    }
    return 0;
}