#include<stdio.h>
#define max 10		//maximum number of processes
#define atr 7		//maximum number of process attributes

void sort(int [][atr], int );						//prototype
void compute(int [][atr], int , float *, float *);	//prototype

void sort(int a[][atr], int size)
{
	int i,j,tmp1,tmp2,tmp3;

	for(i=0; i<size-1; i++)
	{
		for(j=0; j<size-i-1; j++)
		{
			if(a[j][1]>a[j+1][1])	// to sort according to arrival time
			{
				tmp1=a[j][0]; tmp2=a[j][1]; tmp3=a[j][2];
				a[j][0]=a[j+1][0]; a[j][1]=a[j+1][1]; a[j][2]=a[j+1][2];
				a[j+1][0]=tmp1; a[j+1][1]=tmp2; a[j+1][2]=tmp3;
			}
		}
	}
}

void compute(int a[][atr], int size , float *atat , float *awt)
{
	int clock=0,i,j,k;

	for(i=0; i<size; i++)
	{
		if(a[i][1]>clock)		//to check cpu is idle or not
		clock+=(a[i][1]-clock);

		a[i][4]=clock;				//response time
		clock+=a[i][2];
		a[i][3]=clock;				//exit or completion time
		a[i][5]=a[i][3]-a[i][1];	//turn around time
		(*atat)+=a[i][5];			//sum tat
		a[i][6]=a[i][5]-a[i][2];	//waiting time
		(*awt)+=a[i][6];			//sum wt
	}
}

int main()
{
	int a[max][atr]={0},n,i,j;
	float atat=0,awt=0;

	system("clear");	//system command in ubuntu to clear text in terminal 
	printf("\n/* ====== FCFS SCHEDULING  ======= */\n\n");
	printf("\n/* ====================== INPUT =========================== */\n\n");

	printf("enter total no of process : ");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("enter process id : ");
		scanf("%d",&a[i][0]);
		printf("enter arriavl time : ");
		scanf("%d",&a[i][1]);
		printf("enter burst time : ");
		scanf("%d",&a[i][2]);
	}

	sort(a,n);
	compute(a,n,&atat,&awt);

	printf("\n/* ====================== OUTPUT ============================ */\n\n");
	printf("p_id\tAT\tBT\tET\tRT\tTAT\tWT\n\n");

	for(int i=0; i<n; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6]);
	}

	printf("\naverage turn around time = %f\n",atat/n);
	printf("average waiting time = %f\t",awt/n);

	return 0;
}