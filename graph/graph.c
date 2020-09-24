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

void input_graph(graphtype **v,int total_edge)
{
	int i=1;
	while(i<=total_edge)
	{
		int s,d;
		printf("enter source and nextination of edege %d: ",i++);
		scanf("%d%d",&s,&d);

		graphtype *ptr = (graphtype*)malloc(sizeof(graphtype));
		ptr->dest=d;
		ptr->next = v[s];
		v[s]=ptr;
	}
}

void display_graph(graphtype *vertice[],int v)
{
	int e=1;

	for(int i=0; i<v; i++)
	{
		graphtype *ptr = vertice[i];
		while(ptr!=NULL)
		{
			printf("%d-->",ptr->dest);
			ptr=ptr->next; 
			e++;
		}	printf("NULL\n");
	}
}

int main()
{
	int v,e;
	graphtype *vertice[max] = {NULL};
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

	input_graph(vertice,e);			//O(e)
	display_graph(vertice,v);		//O(v+e)
}