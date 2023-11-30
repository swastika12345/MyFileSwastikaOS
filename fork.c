#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int pid;
	pid=fork();
	if(pid == 0){
		printf("\nInside Child Process");
		printf("\nChild ID : %d",getpid());
		printf("\nChild PPID :%d",getppid());
		printf("\nReturn value of PID : %d",pid);
	}
	else if(pid > 0){
		printf("\nIside Parent Process");
		printf("\nParent ID : %d",getpid());
		printf("\nParent PPID : %d",getppid());
		printf("\nReturn value of PID : %d",pid);
	}
	else{
		printf("\nUnsuccessful forking");
		exit(1);
	}
        int pid1;
        pid1=fork();
        if(pid1 == 0){
                printf("\nInside Child Process");
                printf("\nChild ID : %d",getpid());
                printf("\nChild PPID :%d",getppid());
                printf("\nReturn value of PID : %d",pid1);
        }
        else if(pid1 > 0){
                printf("\nIside Parent Process");
                printf("\nParent ID : %d",getpid());
                printf("\nParent PPID : %d",getppid());
                printf("\nReturn value of PID : %d",pid1);
        }
        else{
                printf("\nUnsuccessful forking");
                exit(1);
        }
       int pid2;
        pid2=fork();
        if(pid2 == 0){
                printf("\nInside Child Process");
                printf("\nChild ID : %d",getpid());
                printf("\nChild PPID :%d",getppid());
                printf("\nReturn value of PID : %d",pid2);
        }
        else if(pid2 > 0){
                printf("\nIside Parent Process");
                printf("\nParent ID : %d",getpid());
                printf("\nParent PPID : %d",getppid());
                printf("\nReturn value of PID : %d",pid2);
        }
        else{
                printf("\nUnsuccessful forking");
                exit(1);
        }
return 0;
}
