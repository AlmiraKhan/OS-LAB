#include<stdio.h>
#include<stdlib.h>

struct process
{
    int num;//proc num
    int burst, waiting, turnaround, arrival;
}proc[50];

void fcfs(struct process *proc, int n)
{
    float avg_wait=0,avg_turn=0;
    int total=0;
    float thrput;
    
    printf("FCFS\n\nGantt chart\n|\t");//printing the gantt chart
 
    for(int i=0;i<n;i++)
    {
        printf("P %d\t|\t",i+1);
    }
    printf("\n\n");
    printf("%d\t\t",total);
    for(int i=0;i<n;i++)
    {
        total+=proc[i].burst;
        printf("%d\t\t",total);
        
        proc[i].waiting=total-proc[i].burst;
        proc[i].turnaround=proc[i].waiting+proc[i].burst;
        
    }
    printf("\n\n");
    
    printf("Waiting time\n");
    printf("Process\tWaiting time\n");
    for(int i=0;i<n;i++)
    {
        avg_wait+=proc[i].waiting;
        printf("%d\t%d\n",(i+1),proc[i].waiting); 
    }
    printf("\n");
    printf("Average waiting time in FCFS: %f",avg_wait/n);
    printf("\n\n");
    
    printf("Turnaround time\n");
    printf("Process\tTurnaround time\n");
    for(int i=0;i<n;i++)
    {
        avg_turn+=proc[i].turnaround;
        printf("%d\t%d\n",(i+1),proc[i].turnaround); 
    }
    printf("\n");
    printf("Average turnaround time in FCFS: %f",avg_turn/n);
    printf("\n\n");
    thrput=(float)n/total;
    printf("Average throughput FCFS: %f",thrput);
}

void sjf(struct process *proc, int n)
{
    float avg_wait=0,avg_turn=0;
    int total=0;
    double thrput;
    struct process temp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(proc[i].burst>proc[j].burst)
            {
                temp = proc[i];
                proc[i]=proc[j];
                proc[j]=temp;
            }
        }
    }
    printf(" SJF\n\nGantt chart\n|\t");//printing the gantt chart
 
    for(int i=0;i<n;i++)
    {
        printf("P %d\t|\t",proc[i].num);
    }
    
    total = 0, avg_wait = 0, avg_turn = 0;
    printf("\n\n");
    printf("%d\t\t",total);
    for(int i=0;i<n;i++)
    {
        total+=proc[i].burst;
        printf("%d\t\t",total);
        
        proc[i].waiting=total-proc[i].burst;
        proc[i].turnaround=proc[i].waiting+proc[i].burst;
        
    }
    printf("\n\n");
    
    printf("Waiting time\n");
    printf("Process\tWaiting time\n");
    for(int i=0;i<n;i++)
    {
        avg_wait+=proc[i].waiting;
        printf("%d\t%d\n",(proc[i].num),proc[i].waiting); 
    }
    printf("\n");
    
    
    printf("Average waiting time in SJF: %f",avg_wait/n);
    printf("\n\n");
    
    printf("Turnaround time\n");
    printf("Process\tTurnaround time\n");
    for(int i=0;i<n;i++)
    {
        avg_turn+=proc[i].turnaround;
        printf("%d\t%d\n",(proc[i].num),proc[i].turnaround); 
    }
    printf("\n");
    printf("Average turnaround time in SJF: %f",avg_turn/n);
    printf("\n\n");
    thrput=(float)n/total;
    printf("Average throughput SJF: %f",thrput);    
}

int main()
{
    int n, choice;
    printf("Enter no. of processes\n");
    scanf("%d",&n);

	struct process proc[n];
    for(int i=0;i<n;i++)
    {
       proc[i].num=i+1;
       printf("Enter the burst time of process %d\n",i+1);
       scanf("%d",&proc[i].burst);
    }
    printf("The process table\n");
    printf("Process\tBurst time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\n",(i+1),proc[i].burst); 
    }
    
    
    
    while(1)
    {
        printf("\nEnter\n1.FCFS scheduling\n2.SJF scheduling\n");
        scanf("%d", &choice);
        if(choice==1)
            fcfs(proc, n);
        else if(choice==2)
           sjf(proc, n);
        else
            exit(0);
    }
        
         
}
