// program to represent graph in memory and to implement DFS traversal technique on it
// 1 adjancey matrix reps.
// 2 linked list reps.
// linked array combine reps.

#include<stdio.h>
#include<stdlib.h> // for malloc
#define max 100

typedef struct node {

	int dest;
	struct node *next;
} graphtype;

//global variable easy to access and modify
graphtype *vertice[max];

void dfs(int i,int visited[])
{
	graphtype *ptr;

	if(!visited[i])
	{
		visited[i]=1;
		printf("%d ",i);
	}

	ptr = vertice[i];

	while(ptr!=NULL)
	{
		int j;
		j=ptr->dest;

		if(!visited[j])
		{
			//printf("node processed is %d to %d\n",i+1,j+1);
			dfs(j,visited);		// recursive call
		}
		ptr=ptr->next;
	}
}

void create_edge(int s,int d)
{
	graphtype *ptr = (graphtype*)malloc(sizeof(graphtype));
	ptr->dest=d;
	ptr->next = vertice[s];
	vertice[s]=ptr;
}

void input_graph(int total_edge)
{
	int i=1;
	while(total_edge--)
	{
		int s,d;
		//printf("enter source and destination of edege %d: ",i++);
		scanf("%d%d",&s,&d);

		create_edge(s,d);
	}
}

void display_graph(int v)
{
	int e=1;

	for(int i=0; i<v; i++)
	{
		graphtype *ptr = vertice[i];
		printf("\nedge %d: ",i);
		while(ptr!=NULL)
		{
			printf("->%d",ptr->dest);
			ptr=ptr->next; e++;
		}
	}
}

int main()
{
	int v,e;

	//printf("enter total number of vertices and edges: ");
	scanf("%d%d",&v,&e);

	input_graph(e);			//O(e)
	display_graph(v);		//O(v+e)

	for(int i=0; i<v; i++)
	{
		int visited[max]={0};
		printf("\n");
		dfs(i,visited);
	}
}