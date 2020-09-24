//Complete Binary Tree array implementation is more efficent on comparing to linked list

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 100

void insert(int bst[],int key, int root)
{
	if(bst[root]==0)
		bst[root]=key;
	else if(key<bst[root])
		insert(bst,key,root*=2);
	else
		insert(bst,key,(root*=2)+1);
}

void display(int bst[])
{
	printf("[%d]---%d (size)\n",0,bst[0]);
	for (int i = 1; i <=bst[0]; ++i)
	{
		printf("[%d]---%d\n",i,bst[i]);
	}
}

void inorderTraversal(int bst[],int root)
{
	if(bst[root]==0)
		return;
	inorderTraversal(bst,root*=2);
	printf("%d ",bst[root]);
	inorderTraversal(bst,(root*=2)+1);
}

int levelTraversal(int bst[])	// similar to breadth first search of a graph
{
	int height=0,power=pow(2,height);
	for (int i = 1; i<=bst[0]; ++i)
	{
		if(i==power)
		{
			power = pow(2,++height);
			printf("\nLEVEL %d : %d",height,bst[i]);
		}
		else	printf(" %d",bst[i]);
	}
	return height;
}

int main()
{
	int bst[max]={0};

	while(1)
	{
		int ch;
		printf("\n\tenter choice :\n\t1: Insert \n\t2: Display \n\t3 Delete \n\t0: Exit\n\t");
		scanf("%d",&ch);
		system("clear");
		if(ch==0)	break;
		switch(ch)
		{
			case 1: printf("enter number: ");
					scanf("%d",&ch);	bst[0]++;
					insert(bst,ch,1);	break;
			case 2: //display(bst);	
					//printf("\nheight of bst id %d",levelTraversal(bst)); 
					inorderTraversal(bst,1);	break;
			case 3: break;
			default : printf("Invalid choice\n");
		}
	}
	
	return 0;
}