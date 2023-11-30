#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

int main()
{
	pid_t ppid,pid,cpid;
	ppid=getpid();
	pid=fork();
	if(ppid == getpid())
                printf("\nParent\n");
        else if(cpid == getpid())
                printf("\nChild\n");
        if(pid>0){
                int i=0;
                while(i++ < 5){
                        printf("In the Parent Process\n");
                sleep(1);
                }
	}
	else if(pid==0)
	{
		   int i=0;
                while(i++ < 10){
                        printf("In the Child Process\n");
                        sleep(1);
                        if(i == 3){
                                kill(ppid,SIGKILL);
                                printf("Parent killed.I'm an orphan!!\n");
                        }
                }
	}
	 else{
                printf("Something bad happened");
                exit(EXIT_FAILURE);
        }
return 0;
}



