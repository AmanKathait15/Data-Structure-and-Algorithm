// program to represent graph in memory
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

//global variable easy to access
graphtype *vertice[max] = {NULL};

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
	while(i<=total_edge)
	{
		int s,d;
		printf("enter source and nextination of edege %d: ",i++);
		scanf("%d%d",&s,&d);

		create_edge(s-1,d);
	}
}

void display_graph(int v)
{
	int e=1;

	for(int i=0; i<v; i++)
	{
		graphtype *ptr = vertice[i];
		while(ptr!=NULL)
		{
			printf("edge %d: %d->%d\n",e,i+1,ptr->dest);
			ptr=ptr->next; e++;
		}
	}
}

int main()
{
	int v,e;
	/*
	graphtype tmp; int a,*b;

	printf("%d\n",(int)sizeof(tmp.next));
	printf("%d\n",(int)sizeof(tmp.dest));
	printf("%d\n",(int)sizeof(tmp));
	printf("%d\n",(int)sizeof(a));
	printf("%d\n",(int)sizeof(b));
	*/

	printf("enter total number of vertices and edges: ");
	scanf("%d%d",&v,&e);

	input_graph(e);			//O(e)
	display_graph(v);		//O(v+e)
}