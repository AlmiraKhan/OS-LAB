#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pb,pc,pd,pe,pf,pg,ph,pi;
    
    printf("Process A here\n");
    printf("My PID: %d\n",getpid());
    printf("Parent PID: %d\n",getppid());
    
    pb=fork();
    wait(NULL);
    if(pb<0)
        printf("Failed to create child process\n");
    else if(pb==0)
    {
        printf("Process B here\n");
        printf("My PID: %d\n",getpid());
        printf("Parent PID: %d\n",getppid());
        
        pd=fork();
        wait(NULL);
        if(pd<0)
            printf("Failed to create child process\n");
        else if(pd==0)
        {
            printf("Process D here\n");
            printf("My PID: %d\n",getpid());
            printf("Parent PID: %d\n",getppid());
            
            ph=fork();
            wait(NULL);
            if(ph<0)
                printf("Failed to create child process\n");
            else if(ph==0)
            {
                printf("Process H here\n");
                printf("My PID: %d\n",getpid());
                printf("Parent PID: %d\n",getppid());
                
                pi=fork();
                wait(NULL);
                if(pi<0)
                    printf("Failed to create child process\n");
                else if(pi==0)
                {
                    printf("Process I here\n");
                    printf("My PID: %d\n",getpid());
                    printf("Parent PID: %d\n",getppid());
                    
                    exit(0);
                }
                exit(0);
            }
            exit(0); 
        }
        
        //else
        //{
        pe=fork();
        wait(NULL);
        if(pe<0)
            printf("Failed to create child process\n");
           else if(pe==0)
           {
                printf("Process E here\n");
                printf("My PID: %d\n",getpid());
                printf("Parent PID: %d\n",getppid());
                exit(0);
               
           }
               pf=fork();
               wait(NULL);
               if(pf<0)
               printf("Failed to create child process\n");
               else if(pf==0)
               {
                    printf("Process F here\n");
                    printf("My PID: %d\n",getpid());
                    printf("Parent PID: %d\n",getppid());
                    exit(0);
                   
               }               
                
               
          exit(0);
          
         //}
    }
    else
    {
        pc=fork();
        wait(NULL);
        if(pc<0)
            printf("Failed to create child process\n");
        else if(pc==0)
        {
             printf("Process C here\n");
             printf("My PID: %d\n",getpid());
             printf("Parent PID: %d\n",getppid());
             
             pg=fork();
             wait(NULL);
             if(pg<0)
                printf("Failed to create child process\n");
             else if(pg==0)
             {
                printf("Process G here\n");
                 printf("My PID: %d\n",getpid());
                 printf("Parent PID: %d\n",getppid());
                 
                 exit(0);
             }
             exit(0);
        }
    }
}

