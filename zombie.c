#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(){
	int p;
	p=fork();
	if (p == 0){
	printf("Child Process\n");
	printf("ID=%d,PID=%d",getpid(),getppid());
	}
	else if(p>0){
	sleep(10);
	printf("\nParent Process\n");
	printf("ID=%d,PID=%d",getpid(),getppid());
	printf("Zombie Process");
	}
	while(1){
	printf("Valid");
	}
}
