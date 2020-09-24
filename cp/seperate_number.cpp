#include <bits/stdc++.h>
using namespace std;
#define num unsigned int

void separateNumbers(string s) {

    num l = s.length(),terminate; bool flag=false;
    string digit="";

    if(l>15)	terminate=l/4;
    else		terminate=l/2;

    for(num i=0; i<terminate; i++)
    {
        digit+=s[i];
        string tmp = digit;
        num n = stoi(digit);

        while(tmp.length()<l)    tmp+=to_string(++n);

        if(tmp!=s)  continue;
        cout<<"YES "<<digit<<"\n";  flag=true;
        break;
    }
    if(!flag)
    cout<<"NO\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    num q;
    cin>>q;

    while(q--)
    {
        string s;
        cin>>s;
        separateNumbers(s);
    }
    return 0;
}
