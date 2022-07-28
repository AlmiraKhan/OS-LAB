#include <stdio.h>

int n, m, i, j, k;
int m = 3;
int alloc[10][10], max[10][10], avail[10];
int f[10], ans[10], ind = 0;
int need[10][10];
void safe_seq()
{
	int y = 0;
	for (k = 0; k < 5; k++)
	{
		for (i = 0; i < n; i++)
		{
			if (f[i] == 0)
			{

				int flag = 0;
				for (j = 0; j < m; j++)
				{
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;

	for (int i = 0; i < n; i++)
	{
		if (f[i] == 0)
		{
			flag = 0;
			printf("The following system is not safe");
			break;
		}
	}

	if (flag == 1)
	{
		printf("Following is the SAFE Sequence\n");
		for (i = 0; i < n - 1; i++)
			printf(" P%d ->", ans[i]);
		printf(" P%d", ans[n - 1]);
	}
	printf("\n");
}
int main()
{

	printf("\nEnter the number of processes:\n");
	scanf("%d", &n);
	printf("\nEnter the allocated spaces;\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &alloc[i][j]);
		}
	}
	printf("\nEnter the maximum space;\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &max[i][j]);
		}
	}
	printf("\nEnter the available space;\n");
	for (i = 0; i < m; i++)
	{
		scanf("%d", &avail[i]);
	}

	for (k = 0; k < n; k++)
	{
		f[k] = 0;
	}
	printf("Need matrix:\n");

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{

			need[i][j] = max[i][j] - alloc[i][j];
			printf("%d\t", need[i][j]);

			// printf("\n");
		}
		printf("\n");
	}
	int request[10];
	int x;
	safe_seq();
	printf("Enter the process name which needs additional resource:");
	scanf("%d", &x);

	for (i = 0; i < m; i++)
	{
		printf("Resource request for resource %d :", i + 1);
		scanf("%d", &request[i]);
	}
	int flag1 = 0, flag2 = 0;
	for (i = 0; i < m; i++)
	{
		if (request[i] > need[x][i])
			flag1 = 1;
	}
	if (flag1 == 0)
	{
		for (i = 0; i < m; i++)
		{
			if (request[i] > avail[i])
				flag2 = 1;
		}
		if (flag2 == 0)
		{
			for (i = 0; i < m; i++)
			{
				avail[i] -= request[i];
				alloc[x][i] += request[i];
				need[x][i] -= request[i];
			}
		}
		printf("\nAvailable :");
		for (j = 0; j < m; j++)
			printf("\t%d", avail[j]);
		printf("\nAllocation matrix:");
		for (i = 0; i < n; i++)
		{
			printf("\n");
			for (j = 0; j < m; j++)
			{

				printf("%d\t", alloc[i][j]);
			}
		}

		printf("Need matrix:\n");
		int need[n][m];
		for (i = 0; i < n; i++)
		{
			printf("\n");
			for (j = 0; j < m; j++)
			{
				{
					need[i][j] = max[i][j] - alloc[i][j];
					printf("%d\t", need[i][j]);
				}
			}
		}
		safe_seq();
		return (0);
	}
}