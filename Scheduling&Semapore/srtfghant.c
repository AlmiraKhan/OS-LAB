#include <stdio.h>
int main()
{
      int arr[10], burst[10], temp[10],w[10],t[10],i, sm, cnt = 0, n,flag=0,x;
      float avgwt, avgtt,wt = 0, tt = 0,time, end;
      printf("Enter the Total Number of Processes:");
      scanf("%d", &n);
      printf("\nEnter Details of %d Processes", n);
      for(i=0;i<n;i++)
      {
            printf("\nEnter Arrival Time:");
            scanf("%d", &arr[i]);
            printf("Enter Burst Time:");
            scanf("%d", &burst[i]);
            temp[i] = burst[i];
      }
      for(i=0;i<n;i++)
      {
      		w[i]=0;
            t[i]=0;
      }
      burst[9] = 9999;
      printf("\nGantt chart:\n");
      for(time=0;cnt!=n;time++)
      {
            sm = 9;
            for(i=0;i<n;i++)
            {
                  if(arr[i]<=time && burst[i]<burst[sm] && burst[i]>0)
                  {
                        sm=i;
                        if(flag==0)
                        {

                        	printf("%d ",arr[sm]);
                        	printf(" p%d ",sm+1);
                        	x=sm;
                        }
                        flag=1;
                  }
            }

            burst[sm]--;

            if(burst[sm] == 0)
            {
                  cnt++;
                  end = time + 1;
                  wt=wt+end-arr[sm]-temp[sm];
                  w[sm]+=end - arr[sm] - temp[sm];
                  tt = tt+end-arr[sm];
                  t[sm]+= end - arr[sm];
            }
            if(sm!=x)
            {
            	printf(" %d ",(int)time);
            	printf(" p%d ",sm+1);
            	x=sm;
			}
      }
      printf(" %d ",(int)end);
      for(i = 0; i < n; i++)
      {
      	 	printf("\np%d wt=%d  tt=%d", i+1,w[i],t[i]);
      }
      avgwt = wt/n;
      avgtt = tt/n;
      printf("\n\nAverage Waiting Time:%f\n", avgwt);
      printf("Average Turnaround Time:%f\n", avgtt);
      printf("Throughput:%f\n",n/end);
      return 0;
}