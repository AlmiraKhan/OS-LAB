#include<stdio.h>
#include<stdlib.h>

struct process {
	int num;
	float burst;
	float arrival;
	float remaining;
	float waiting;
	float turnaround;
};

void rr(struct process *proc, int n, float q)
{
		int i, j, count = 0;
		
		
		printf("\nROUND ROBIN\n\nThe process chart is given below\n");
		printf("\nProcess\t\tBurst Time (ms)\t)\n");
		for(i=0; i<n; i++) {
			printf("P%d\t\t%.3f\t\n", proc[i].num, proc[i].burst);
		}
		
		for(i=0; i<n; i++) 			//intitialzing remaining times to burst times itself
		proc[i].remaining = proc[i].burst;
		
		//Gantt chart here---
		printf("\n|");
		for(i=0; count!=n; i=(i+1)%n)
		{
			if(proc[i].remaining != 0) 
			{
				printf("\tP%d\t|", proc[i].num);
				if(q < proc[i].remaining)
					proc[i].remaining -= q;
				else
				{
					proc[i].remaining = 0;
					count++;

				}
					
			}
		}
		printf("\n");
		//----
		
		for(i=0; i<n; i++)				//intitialzing remaining times to burst times itself again
		proc[i].remaining = proc[i].burst;
		
		float total_time = 0, avg_wait = 0, avg_turn = 0;
		
		for(i=0, count=0; count != n; i=(i+1)%n)
		{
			if(proc[i].remaining != 0)
			{
				if(proc[i].remaining <= q)
				{
					
					total_time += proc[i].remaining;
					proc[i].waiting=total_time-proc[i].burst;
        				proc[i].turnaround=proc[i].waiting+proc[i].burst;
					proc[i].remaining = 0;
					count++;
				} 
				else 
				{
					total_time += q;
					proc[i].remaining -= q;
				}
				printf("\t\t%.1f", total_time);
			}
		}
		
	printf("\n\nWaiting Time chart:\n");
	for(i=0; i<n; i++)
	{
		avg_wait += proc[i].waiting;
		printf("P%d : %f\n", proc[i].num, proc[i].waiting);
	}
	printf("\nAverage Waiting Time = %.2f ms\n", avg_wait/n);
	
	printf("\nTurnaround Time chart:\n");
	for(i=0; i<n; i++)
	{
		avg_turn += proc[i].turnaround;
		printf("P%d : %f\n", proc[i].num, proc[i].turnaround);
	}
	printf("\nAverage Turnaround Time = %f ms", avg_turn/n);
		
}

int main() {
	int n, m = 0,choice;
	printf("Enter the number of processes\n");
	scanf("%d", &n);
	float q;
	struct process proc[n];
	
	for(int i=0; i<n; i++) {
		printf("\nEnter burst time of process %d (in ms)\n", i+1);
		scanf("%f", &proc[i].burst);
		proc[i].num = i+1;
	}
	
	printf("\nThe process chart is given below\n");
	printf("\nProcess\t\tBurst Time (ms)\t\t\n");
	for(int i=0; i<n; i++) {
		printf("P%d\t\t%.3f\t\n", proc[i].num, proc[i].burst);
	}
	while(1)
	{
		printf("Choose the time quantum\n1.2 ms\n2.4 ms\n3.8 ms\n4.10 ms\n5.EXIT\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
				q=2;
				rr(proc, n, q); 
				break; 
			case 2: 
				q=4;
				rr(proc, n, q); 
				break;
			case 3: 
				q=8;
				rr(proc, n, q); 
				break;
			case 4: 
				q=10;
				rr(proc, n, q); 
				break;
			case 5: return 0;
			
		}
	}
	
}
