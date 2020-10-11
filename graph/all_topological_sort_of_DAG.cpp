#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/all-topological-sorts-of-a-directed-acyclic-graph/

void all_topological_sort(vector<int> graph[],vector<int> &in_degree,vector<int> &visited,vector<int> &res,int V)
{
	bool flag = false;
  
    for (int i = 0; i < V; i++) 
    { 
        if (in_degree[i] == 0 && !visited[i]) 
        { 
        	res.push_back(i); visited[i] = true; 

            //  reducing indegree of adjacent vertices 

            for(auto j = graph[i].begin(); j != graph[i].end(); j++) in_degree[*j]--; 
  
            all_topological_sort(graph,in_degree,visited,res,V); 
  
            // resetting visited, res and indegree for backtracking 
            
            visited[i] = false;	res.erase(res.end() - 1); 
            
            for (auto j = graph[i].begin(); j != graph[i].end(); j++) in_degree[*j]++; 
  
            flag = true; 
        } 
    } 
  
    //  We reach here if all vertices are visited. So we print the solution here 
    
    if (!flag) 
    { 
        for (int i = 0; i < res.size(); i++) cout << res[i] << " "; cout<<"\n"; 
    } 	
}

int main()
{
	int V,E; cin>>V>>E; vector<int> res,in_degree(V,0) ,visited(V,0) , graph[V];	// graph must be DAG for topological sort

	for(int i=0; i<E; i++)
	{
		int u,v; cin>>u>>v; graph[u].push_back(v); // directed edge

		in_degree[v]++;
	}

	all_topological_sort(graph,in_degree,visited,res,V);

	return 0;
}

// Test Case

/*
6 6
5 2 
5 0 
4 0 
4 1 
2 3 
3 1
*/

/*
6 6
5 0 5 2 2 3 4 0 4 1 1 3
*/

/*
4 3
3 0 1 0 2 0
*/