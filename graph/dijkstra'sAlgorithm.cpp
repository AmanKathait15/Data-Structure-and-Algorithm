#include<bits/stdc++.h>
using namespace std;
#define num int

void display(vector<pair<num,num>> graph[], num size)
{
	for(num i=0; i<size; i++)
	{
		printf("\ngraph[%d] : ",i);

		for(auto j=graph[i].begin(); j!=graph[i].end(); j++)
		{
			printf("--->[%d|%d]",j->first,j->second);
		}
	}
}
int minDistance(int dist[], bool sptSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			{
				min = dist[v], min_index = v;
			}

	return min_index; 
} 
int printSolution(int dist[]) 
{ 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; 

	bool sptSet[V];

	for (int count = 0; count < V - 1; count++) { 
		printSolution(dist);
		 
		int u = minDistance(dist, sptSet); 

		sptSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v];
	} 
	printSolution(dist); 
} 


int main()
{
	num v,e;
	//cout<<"enter number of vertices and edges : ";
	cin>>v>>e;

	vector<pair<num,num>> graph[v];

	for(num i=0; i<e; i++)
	{
		num s,d,w;
		//cout<<"enter source destination and weight of edge "<<(i+1)<<" : ";
		cin>>s>>d>>w;

		graph[s].push_back({d,w});
		graph[d].push_back({s,w});
	}
	display(graph,v);
	dijkstra(graph,visited,dist,v,0,0);
	return 0;
}