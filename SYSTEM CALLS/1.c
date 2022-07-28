#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int isPrime(int i)
{
    int j;
    for(j=2;j<=i/2;j++)
    {
        if(i%j==0)
            return 0;
    }
    return 1;
}


int main()
{
    pid_t pid;
    int n;
    printf("Enter the limiting value:");
    scanf("%d",&n);
    
    pid=fork();
    if(pid<0)
        printf("Failed to create child process");
    else if(pid==0)
    {
        //child process
        int n1=0,n2=1,f=n1+n2,k=3;
        printf("--child process--");
        printf("%d %d",n1,n2);
        while(k<=n)
        {
            printf(" %d",f);
            n1=n2;
            n2=f;
            f=n1+n2;
            k++;
        }
        printf("\n");
    }
    else
    {
        //parent process
        int l=1,i=2;
        wait(NULL);
        printf("--parent process--");
        
        while(l<=n)
        {
           int result = isPrime(i);
                if(result==1)
                {
                   printf("%d ",i);
                   l++;         
                }
                        
                i++;     
        }
        
    }
    return 0;
        
}

