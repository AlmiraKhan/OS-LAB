#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t p1, p2, p3, p4,p5,p6,pc,pg;
    printf("Process A here\n");
    printf("Parent process ID:%d\n",getppid());
    printf("My process ID:%d\n", getpid());

    p1 = fork();
    wait(NULL);
    if (p1 < 0)
        printf("Failed to create child process\n");
    else if (p1 == 0)
    {
        printf("Process B here\n");
        printf("Parent process ID:%d\n", getppid());
        printf("My process ID:%d\n", getpid());
        p2 = fork();
        wait(NULL);
                if (p2 < 0)
            printf("Failed to create child process\n");
        else if (p2 == 0)
        {
            printf("Process D here\n");
            printf("Parent process ID:%d\n", getppid());
            printf("My process ID:%d\n", getpid());
            p3 = fork();
            wait(NULL);
            if (p3 < 0)
                printf("Failed to create child process\n");
            else if (p3 == 0)
            {
                printf("Process H here\n");
                printf("Parent process ID:%d\n", getppid());
                printf("My process ID:%d\n", getpid());
                p4= fork();
                wait(NULL);
                if (p4 < 0)
                    printf("Failed to create child process\n");
                else if (p4 == 0)
                {
                    printf("Process I here\n");
                    printf("Parent process ID:%d\n", getppid());
                    printf("My process ID:%d\n", getpid());
                    exit(0);
                }
                exit(0);
                
                
            }
            exit(0);
            
        }

        p5=fork();
        wait(NULL);
        if (p5 < 0)
                    printf("Failed to create child process\n");
        else if (p5 == 0)
                {
                    printf("Process E here\n");
                    printf("Parent process ID:%d\n", getppid());
                    printf("My process ID:%d\n", getpid());
                    exit(0);
                }
        p6=fork();
        wait(NULL);
        if (p6 < 0)
                    printf("Failed to create child process\n");
        else if (p6 == 0)
                {
                    printf("Process F here\n");
                    printf("Parent process ID:%d\n", getppid());
                    printf("My process ID:%d\n", getpid());
                    exit(0);
                }
        exit(0);
        
        
        
                
    }
    pc=fork();
    wait(NULL);
    if(pc<0)
    {
        printf("fail");
    }
    else if(pc==0)
    {
                    printf("Process C here\n");
                    printf("Parent process ID:%d\n", getppid());
                    printf("My process ID:%d\n", getpid());
                    pg=fork();
                    wait(NULL);
                    if(pg<0)
                    {
                        printf("fil");
                    }
                    else if (pg==0)
                    {
                        printf("Process G here\n");
                    printf("Parent process ID:%d\n", getppid());
                    printf("My process ID:%d\n", getpid());
                    }
    }
    return 0;
}