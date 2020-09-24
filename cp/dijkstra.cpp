/*
 
    Name - Aman Kathait
    Sec A
    roll no - 11
    univ roll no - 2012483
    phone no - 7983303133
    email - agnikathait17149@gmail.com

 */

#include<bits/stdc++.h> 
using namespace std; 
# define INF 10000000
 
typedef pair<int, int> iPair; 

class Graph 
{ 
    int V; 

    list< pair<int, int> > *adj; 

public: 
    Graph(int V); 
 
    void addEdge(int u, int v, int w); 

    void shortestPath(int s); 
}; 

Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 

void Graph::shortestPath(int src) 
{ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

    vector<int> dist(V, INF); 

    pq.push(make_pair(0, src)); 
    dist[src] = 0; 

    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 

        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).first; 
            int weight = (*i).second; 

            if (dist[v] > dist[u] + weight) 
            { 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 

    printf("Vertex Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

int main() 
{ 
    int v,e;
    cout<<"enter number of vertices and edges : ";
    cin>>v>>e;

    Graph g(v);

    while(e--)
    {
        int s,d,w;
        cout<<"enter source destination and weight : ";
        cin>>s>>d>>w;

        g.addEdge(s,d,w);
    }

    int s;
    cout<<"enter source : ";
    cin>>s;
    g.shortestPath(s); 

    return 0; 
} 
