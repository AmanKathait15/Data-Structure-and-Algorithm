#include<bits/stdc++.h>
using namespace std;

/*BLUE PRINT FOR GRAPH DATA STRUCTURE*/
struct graphtype 
{
	int dest;
	int color;
	graphtype *next;
};

void input_graph(graphtype *vertice[], int total_edge)
{
	int i=1;
	while(total_edge--)
	{
		int s,d;
		printf("enter source and destination of edege %d: ",i++);
		scanf("%d%d",&s,&d);

		graphtype *ptr = new(graphtype);
		ptr->dest = d;
		ptr->next = vertice[s];
		vertice[s]=ptr;
	}
}

void display_graph(graphtype *vertice[],int v)
{
	int e=1;

	for(int i=0; i<v; i++)
	{
		graphtype *ptr = vertice[i];
		printf("\nvertice[%d]--->",i);
		while(ptr!=NULL)
		{
			printf("%d--->",ptr->dest);
			ptr=ptr->next;
			e++;
		}	printf("NULL\n");
	}
}

void bfs(graphtype *vertice[], queue<int> Queue,int parent[],int s)
{
	graphtype *ptr = vertice[s];

	printf("node processed id %d\n",ptr->color);

	while(ptr!=NULL)
	{
		int x = ptr->dest;

		if(parent[x] == x)
		{
			parent[x] = s;
			Queue.push(x);
		}
		ptr=ptr->next;
	}

	//showParent(parent,6);

	if(!Queue.empty())
	{
		s = Queue.front();	Queue.pop();
		bfs(vertice,Queue,parent,s);
	}
}

void setParent(int parent[], int v)
{
	for (int i = 0; i < v; ++i)
	{
		parent[i]=i;
	}
}

void showParent(int parent[], int v)
{
	cout<<"\n";
	for (int i = 0; i < v; ++i)
		cout<<parent[i]<<" ";
	cout<<"\n";
}

void find(int parent[], int s,int d)
{
	printf("shortest path : %d<--->",d);
	while(parent[d]!=s)
		printf("%d<--->",d=parent[d]);
	printf("%d\n",s);
}

int main()
{
	int v,e;
	cin>>v>>e;
	int parent[v],s,d;

	graphtype *vertice[v]={NULL},g;
	
	setParent(parent,v);
	input_graph(vertice,e);			//O(e)
	display_graph(vertice,v);		//O(v+e)

	queue<int> Queue;

	printf("Enter source and destination: ");
	scanf("%d%d",&s,&d);	parent[s]=-1;

	bfs(vertice,Queue,parent,s);
	find(parent,s,d);

	return 0;
}