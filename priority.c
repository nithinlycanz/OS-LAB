#include<stdio.h>

int main()
{

	int bt[20],p[20],at[20],wt[20],tat[20],pr[20],i,j,n,pos,temp;
	float avg_wt,avg_tat,total=0;
	printf("Enter Total Number of process:");
	scanf("%d",&n);
	
	printf("\nEnter Arrival Time,Burst Time and Priority\n");
	for(i=0;i<n;i++)
	{
		printf("\nP[%d]\n",i+1);
		
		printf("Arrival Time:");
		scanf("%d",&at[i]);
		printf("Burst Time:");
		scanf("%d",&bt[i]);
		printf("Priority");
		scanf("%d",&pr[i]);
		p[i]=i+1;
	}
	
	for(i=0;i<n;i++);
	{
	pos=i;
	for(j=i+1;j<n;j++)
		{
			if(pr[j]<pr[pos])
				pos=j;
				
		}
		
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
	
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
	
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	
	}
	wt[0]=0;

	for(i=1;i<n;i++)
	{

		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[j];
		
		total+=wt[i];
	}


	avg_wt=total/n;
	float ttotal=0;
	
	printf("\nProcess\t  Arrival Time\t  BUrst Time  \tWaiting TIME\tTurnaround Time");
	for(i=0;i<n;i++)
	{
	
		tat[i]=bt[i]+wt[i];
		ttotal+=tat[i];
		printf("\nP[%d]\t\t  %d\t\t  %d\t\t  %d\t\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
	}
	avg_tat=ttotal/n;
	printf("\n\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
		
return 0;
}





