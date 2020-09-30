include<bits/stdc++.h>
using namespace std;

//https://www.hackerrank.com/challenges/components-in-graph

struct disJointSet 
{ 
    int parent; 
    int rank; 
};

int find(vector &djs,int i) // logn 
{ 
    int tmp = i;

    while(djs[i].parent!=i)
    {
        i = djs[i].parent;
    }

    djs[tmp].parent = i;

    return i;
}

int Union_by_rank(vector &djs,int x,int y) 
{ 
    int px = find(djs,x) , py = find(djs,y);

    if(px==py) return 1;

    if(djs[px].rank > djs[py].rank)         
    { 
        djs[py].parent = px; 
        djs[px].rank+= djs[py].rank;
        djs[py].rank=0; 
    }
    else     
    { 
        djs[px].parent = py; 
        djs[py].rank+= djs[px].rank;
        djs[px].rank=0; 
    }
    return 0;

} 

int main() 
{ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int V; cin>>V; vector djs(2*V);

    for(int i=0; i<2*V; i++) djs[i].parent=i, djs[i].rank=1; 

    for(int i=0; i<V; i++)
    {
        int x,y; cin>>x>>y;    Union_by_rank(djs,x,y);
    }

    int minc=INT_MAX,maxc=INT_MIN;

    for(int i=0; i<2*V; i++)
    {
        int c = djs[i].rank;

        if(c>1)
        {
            if(c<minc) minc=c;
            if(c>maxc) maxc=c;
        }
    }

    cout<<minc<<" "<<maxc<<"\n";
    
    return 0;
}