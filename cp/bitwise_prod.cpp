#include <bits/stdc++.h>
#define num long long int 
using namespace std;


num find_z(num l,num r,num z)
{
    if(z>=l && z<=r)
    {
        return z;
    }
    else if(z<l)
    {
        z = (num)pow(2,(log(l)/log(2)));

        while(z<l)
            z+=(z/2);

        find_z(l,r,z);
    }
    else
    {

    }

}


int main() {
    // your code goes here
    num t;
    cin>>t;
    
    while(t--)
    {
        num x,y,l,r,z,m;

        cin>>x>>y>>l>>r;

        if(abs(l-r)<=100)
        {
            num maximum = (x & i)*(y & i); z=i;
            for(num i=l+1; i<=r; i++)
            {
                num tmp = (x & i)*(y & i);

                if(tmp > maximum)
                {
                    maximum = tmp; z=i;
                }
            }

            cout<<z<<"\n"; continue;
        }

        m = 

        z = (x | y);

        z = (num)pow(2,ceil(log(z+1)/log(2))) - 1;

        z = find_z(l,r,z);

        cout<<z<<"\n";
    }
    return 0;
}
