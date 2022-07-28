#include<stdio.h>
#define n 4
int comp_phil = 0,i;

struct fork
{
    int taken;
}forkavail[n];
 
struct philosophers
{
    int left;
    int right;
}philostatus[n];
 
void Eat(int id)
{ 
    if(philostatus[id].left==10 && philostatus[id].right==10)
            printf("Philosopher %d completed eating\n",id+1);
    //if already completed dinner
    else if(philostatus[id].left==1 && philostatus[id].right==1){
                //if just taken two forks
                printf("Philosopher %d completed eating\n",id+1);
                philostatus[id].left = philostatus[id].right = 10; //10->completed dinner
                int otherFork = id-1;
                if(otherFork== -1)
                    otherFork=(n-1);
                forkavail[id].taken = forkavail[otherFork].taken = 0; //releasing forks
                printf("Philosopher %d released fork %d and fork %d\n",id+1,id+1,otherFork+1);
                comp_phil++;
            }
    else if(philostatus[id].left==1 && philostatus[id].right==0){ //left already taken, trying for right fork
                    if(id==(n-1)){
                        if(forkavail[id].taken==0){ //last phil in reverse dir
                            forkavail[id].taken = philostatus[id].right = 1;
                             printf("Fork %d taken by philosopher %d\n",id+1,id+1);
                        }else{
                           printf("Philosopher %d is waiting for fork %d\n",id+1,id+1);
                        }
                    }else{ //except last philosopher case
                        int dupid = id;
                        id-=1;
    
                        if(id== -1)
                            id=(n-1);
    
                        if(forkavail[id].taken == 0){
                            forkavail[id].taken = philostatus[dupid].right = 1;
                            printf("Fork %d taken by Philosopher %d\n",id+1,dupid+1);
                        }else{
                            printf("Philosopher %d is waiting for Fork %d\n",dupid+1,id+1);
                        }
                    }
                }
                else if(philostatus[id].left==0){ //nothing taken yet
                        if(id==(n-1)){
                            if(forkavail[id-1].taken==0){ //last phil in reverse dir
                                forkavail[id-1].taken = philostatus[id].left = 1;
                                printf("Fork %d taken by philosopher %d\n",id,id+1);
                            }else{
                                printf("Philosopher %d is waiting for fork %d\n",id+1,id);
                            }
                        }else{ //except last philosopher case
                            if(forkavail[id].taken == 0){
                                forkavail[id].taken = philostatus[id].left = 1;
                                printf("Fork %d taken by Philosopher %d\n",id+1,id+1);
                            }else{
                                printf("Philosopher %d is waiting for Fork %d\n",id+1,id+1);
                            }
                        }
            }
}
 
int main()
{
    for(i=0;i<n;i++)
            forkavail[i].taken=philostatus[i].left=philostatus[i].right=0;
    while(comp_phil<n){
    for(i=0;i<n;i++)
                Eat(i);
    printf("\nNumber of philosophers completed eating %d\n\n",comp_phil);
    } 
    return 0;
}