#include<stdio.h>

int main()
{
	int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
	printf("Enter the no. of process\t:(Maximum 20)");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter P[%d] burst time\n",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++){
		wt[i]+=bt[j];
		}
	}
	printf("\nProcess\tBurst Time\tWaiting time\tTurnaround Time\n");
	for(i=0;i<n;i++){
	tat[i]=bt[i]+wt[i];
	avwt+=wt[i];
	avtat+=tat[i];
	printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	}	
	avwt/=i;
	avtat/=i;
	printf("\nAverage Turn around time and Average Waiting Time are %d & %d ",avtat,avwt);
	return 0;
}
