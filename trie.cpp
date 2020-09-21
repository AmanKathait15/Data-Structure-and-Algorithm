#include<bits/stdc++.h>
using namespace std;
#define num long int

struct trie
{
    num isEndofword = 0;

    map<char,trie*> mp;
};


void insert(trie *root,string str)
{
    num l = str.length();

    for(num i=0; i<l; i++)
    {
        char ch = str[i];

        if(!(root->mp[ch]))
        {
            trie *ptr = new trie;
            root->mp[ch] = ptr;
            root->isEndofword += 1;
            root = root->mp[ch];
        }
        else
        {
            root->isEndofword += 1;
            root = root->mp[ch];
        }
    }
    root->isEndofword += 1;
}

short search(trie *root,string str)
{
    num l = str.length();

    for(num i=0; i<l; i++)
    {
        char ch = str[i];

        if(!(root->mp[ch])) return 0;
        else root = root->mp[ch];

        if(i==l-1) return root->isEndofword;
    }

    return root->isEndofword;
}

void display(trie *root,string str)
{

    for(auto i=(root->mp).begin(); i!=(root->mp).end(); i++)
    {
        if((i->second)->isEndofword)
            cout<<str+(i->first)<<"\n";

        display(i->second,str+(i->first));
    }
}

int main()
{
    trie root; num t; cin>>t;

    while(t--)
    {
        string ch,key; cin>>ch>>key;

        if(ch=="add")   insert(&root,key);
        else            cout<<search(&root,key)<<"\n";

        //display(&root,"");
    }

    return 0;
}