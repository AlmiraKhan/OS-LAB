#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int isprime(int);

int main()
{
    pid_t pid;
    int n;
    int n1=0,n2=1,f,result;
    printf("Enter the limiting value n:\n");
    scanf("%d",&n);
    pid=fork();
    if(pid<0)
        printf("Failed to create child process\n");
    else if(pid==0)
    {
        //write fibonacci code

        printf("\n--Child process executing code for fibonacci--\n");
        
        printf("%d,%d",n1,n2);
        f=n1+n2;
        while(f<=n)
        {
            printf(",%d",f);
            n1=n2;
            n2=f;
            f=n1+n2;  
        }
        printf("\n");
    }
    else
    {
        //write prime numbers code
                        wait(NULL);
        printf("\n--Parent process executing code for prime numbers--\n");
        for(int i=2;i<=n;i++)
        {
            result=isprime(i);
            if(result==1)
                printf("%d ",i);
            
        }
        printf("\n");

    }
    return 0;
}
int isprime(int i)
{
    int j;
    for(j=2;j<=i/2;j++)
    {
        if(i%j==0)
        {   
            return 0;
            //break;
        }    
    }
    return 1;
}