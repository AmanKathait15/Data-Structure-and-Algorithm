#include<iostream> 
using namespace std;

int value(char symbol)
{
    switch(symbol)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    
    return 0;
}

int convert(string roman)
{
    int l = roman.length(),res=0,i=0;

    for(i=0; i<l-1; i++)
    {
        int x=value(roman[i]),y=value(roman[i+1]);

        if(x>=y) res+=x;
        else 
        {
            res+=y-x; i++;
        }
    }

    if(i==l-1) res += value(roman[i]);

    return res;
}

int main() 
{
    int t; cin>>t;

    while(t--)
    {
        string str; cout<<"enter roman string : "; cin>>str;
        cout<<"value in decimal : "<<convert(str)<<"\n";
    }

    return 0; 
} 