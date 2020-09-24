/*HEAP IS ABSTRACT DATA STRUCTURE 
  PROPERTIES OF HEAP :-
1: HEAP IS A COMPLETE BINARY TREE EXCEPT THE LAST LEVEL
2: TYPE MAX HEAP : ALL PARENT NODE HAS VALUE GREATER THEN ITS CHILD
		MIN HEAP : ALL PARENT NODE HAS VALUE LESS THEN ITS CHILD
3: PARTIALLY ORDER DATA STRUCTURE AND MORE EFFICENTLY USED BY ARRAY
4: USED IN HEAP SORT
*/

#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 100

void insertMaxHeap(int maxHeap[],int key, int now)
{
	while(now/2!=0 && maxHeap[now/2]<key)
	{
		maxHeap[now] = maxHeap[now/2];	now/=2;
	}
	maxHeap[now]=key;
}

void insertMinHeap(int minHeap[],int key, int now)
{
	while(now/2!=0 && minHeap[now/2]>key)
	{
		minHeap[now] = minHeap[now/2];	now/=2;
	}
	minHeap[now]=key;
}

int extractMaxHeap(int maxHeap[])
{
	int maxElement = maxHeap[1],lastElemnet=maxHeap[maxHeap[0]--],size=maxHeap[0],now=1,child = 2*now;

	while(child<=size && lastElemnet < maxHeap[child])
	{
		//printf("%d\n",child);
		if((child+1)<=size && (maxHeap[child+1]>maxHeap[child]))
			child++;
		maxHeap[now]=maxHeap[child];
		now = child;
		child = 2*now;
	}

	maxHeap[now] = lastElemnet;
	maxHeap[size+1] = maxElement;

	return maxElement;
}

int extractMinHeap(int minHeap[])
{
	int minElement = minHeap[1],lastElemnet=minHeap[minHeap[0]--],size=minHeap[0],now=1,child = 2*now;

	while(child<=size && lastElemnet > minHeap[child])
	{
		//printf("%d\n",child);
		if((child+1)<=size && (minHeap[child+1]<minHeap[child]))
			child++;
		minHeap[now]=minHeap[child];
		now = child;
		child = 2*now;
	}

	minHeap[now] = lastElemnet;
	minHeap[size+1] = minElement;

	return minElement;
}

void display(int bst[])
{
	printf("[%d]---%d (size)\n",0,bst[0]);
	for (int i = 1; i <=bst[0]; ++i)
	{
		printf("[%d]---%d\n",i,bst[i]);
	}
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
	int minHeap[max]={0},maxHeap[max]={0};

	while(1)
	{
		int ch;
		printf("\n\tenter choice :\n\t1: Insert \n\t2: Display minHeap \n\t3: Display maxHeap \n\t4: extractMinHeap \n\t5: extractMaxHeap \n\t6: Heapsort \n\t0: Exit\n\t");
		scanf("%d",&ch);
		system("clear");
		if(ch==0)	break;
		switch(ch)
		{
			case 1: printf("enter number: ");
					scanf("%d",&ch);
					minHeap[0]++; maxHeap[0]++;	// use to store size;
					insertMinHeap(minHeap,ch,minHeap[0]);		//O(logn)	worse case complexity
					insertMaxHeap(maxHeap,ch,maxHeap[0]);		//O(logn)
					break;
			case 2: if(minHeap[0]==0)	printf("minHeap is empty\n");
					else	display(minHeap);	
					printf("\nheight of minHeap is %d",levelTraversal(minHeap)); 
					break;
			case 3: if(maxHeap[0]==0)	printf("maxHeap is empty\n");
					else	display(maxHeap);	
					printf("\nheight of maxHeap is %d",levelTraversal(maxHeap)); 
					break;

			case 4: if(minHeap[0]==0)	printf("minHeap is empty\n");
					else	printf("\nelement extract from minHeap is  %d",extractMinHeap(minHeap)); 
					break;
			case 5: if(maxHeap[0]==0)	printf("maxHeap is empty\n");
					else	printf("\nelement extract from maxHeap is %d",extractMaxHeap(maxHeap)); 
					break;

			case 6: printf("enter 1 for acsending and 2 for decsendin : ");
					scanf("%d",&ch);

					if(ch==1)
					{
						int size=maxHeap[0];
						while(maxHeap[0])
							printf("%d ",extractMaxHeap(maxHeap));
						printf("\n");
						for (int i = 1; i <=size; ++i)
						{
							printf("%d ",maxHeap[i]);
						}
					}
					else
					{
						int size=minHeap[0];
						while(minHeap[0])
							printf("%d ",extractMaxHeap(minHeap));
						printf("\n");
						for (int i = 1; i <=size; ++i)
						{
							printf("%d ",minHeap[i]);
						}
					}
					break;

			default : printf("Invalid choice\n");
		}
	}

	return 0;
}