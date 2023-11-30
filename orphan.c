#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int p;
	p=fork();
	if(p == 0){
		printf("\nChild Process ID=%d, PID=%d",getpid(),getppid());
		sleep(10);
		printf("\nOrphan Process\n");
	}
	else if(p>0)
		printf("\nParent Process ID=%d, PID=%d",getpid(),getppid());
	else
		printf("Terminated\n");
return 1;
}
