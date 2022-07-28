#include <stdio.h>
#include <stdlib.h>

int arr[10], burst[10], burst2[10], temp[10], p[10], opt, i, prior, w[10], t[10], count = 0, n, flag = 0, x, k, prev;
float avgwt, avgtt, wt = 0, tt = 0, time, end, tmp;

void pre()
{
	for (i = 0; i < n; i++)
	{
		w[i] = 0;
		t[i] = 0;
	}
	wt = 0;
	tt = 0;
	count = 0;
	flag = 0;
	printf("\nGantt chart:\n");
	for (time = 0; count != n; time++)
	{
		prior = 9;
		for (i = 0; i < n; i++)
		{
			if (arr[i] <= time && p[i] < p[prior] && burst[i] > 0)
			{
				prior = i;
			}
		}
		if (prior == 9)
			continue;
		if (flag == 0)
		{

			printf("%d ", arr[prior]);
			printf(" p%d ", prior + 1);
			x = prior;
		}
		flag = 1;

		burst[prior]--;

		if (burst[prior] == 0)
		{
			count++;
			end = time + 1;
			wt = wt + end - arr[prior] - temp[prior];

			w[prior] += end - arr[prior] - temp[prior];
			tt = tt + end - arr[prior];
			t[prior] += end - arr[prior];
		}
		if (prior != x)
		{
			printf(" %d ", (int)time);
			printf(" p%d ", prior + 1);
			x = prior;
		}
	}
	printf(" %d ", (int)end);
	
	printf("| PID | Burst Time | Waiting Time | Turnaround Time |\n");
	
	for(i=0; i<n; i++) 
	{
		printf("\n| p%2d  |     %2d     |      %2d      |        %2d    |\n",i+1,burst2[i], w[i], t[i] );
		
	}
	printf(" ");
	avgwt = wt / n;
	avgtt = tt / n;
	printf("\n\nAverage Waiting Time:%f\n", avgwt);
	printf("Average Turnaround Time:%f\n", avgtt);
	printf("Throughput:%f\n", n / end);
}

void nonpre()
{
	for (i = 0; i < n; i++)
	{
		w[i] = 0;
		t[i] = 0;
	}
	flag = 0;
	count = 0;
	wt = 0;
	tt = 0;
	printf("\nGantt chart:\n");
	for (time = 0; count != n; time++)
	{
		prior = 9;
		for (i = 0; i < n; i++)
		{
			if (arr[i] <= time && p[i] < p[prior] && burst2[i] > 0)
			{
				prior = i;
			}
		}
		if (prior == 9)
			continue;
		if (flag == 0)
		{

			printf("%d ", arr[prior]);
		}
		flag = 1;
		while (burst2[prior] > 0)
		{

			burst2[prior]--;

			time++;
			for (k = 0; k < n; k++)
			{
				if (burst2[k] != 0 && k != prior)
				{
					w[k]++;
				}
			}
		}

		if (burst2[prior] == 0)
		{
			time--;
			count++;
			end = time + 1;
			wt = wt + end - arr[prior] - temp[prior];

			tt = tt + end - arr[prior];
		}

		printf(" p%d ", prior + 1);
		printf(" %d ", (int)time + 1);
	}
	
	printf("| PID | Burst Time | Waiting Time | Turnaround Time |\n");

	for(i=0; i<n; i++) 
	{
		printf("\n| p%2d  |     %2d     |      %2d      |        %2d    |\n",i + 1, burst[i], w[i] - arr[i], w[i] - arr[i] + temp[i]);
		
	}
	printf(" ");
	avgwt = wt / n;
	avgtt = tt / n;
	printf("\n\nAverage Waiting Time:%f\n", avgwt);
	printf("Average Turnaround Time:%f\n", avgtt);
	printf("Throughput:%f\n", n / end);
}

int main()
{
	printf("\nEnter no of Processes:");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("\nEnter Arrival Time, Burst time and priority of process %d: ", i+1);
		scanf("%d%d%d", &arr[i],&burst[i],&p[i]);
		temp[i] = burst[i];
		burst2[i] = burst[i];
	}
	p[9] = 9999;

	while (1)
	{
		printf("Choose a scheduling algorithm\n1.pre emptive\n2.non preemprive\n3.exit\n\nEnter your option: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			pre();
			break;

		case 2:
			nonpre();
			break;
		case 3:
			exit(0);
		default:
			printf("\nEnter valid choice!");
		}
	}
	return 0;
}
