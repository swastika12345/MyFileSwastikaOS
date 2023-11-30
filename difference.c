#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	int var;
	printf("Enter a number:");
	scanf("%d",&var);
	int pid;
	pid=fork();
	if(pid<0){
		printf("Fork failed");
		exit(1);
	}
	else if(pid == 0){
		var+=10;
		printf("\nInside Child Process\n");
		printf("Modified value is %d\n",var);
	}
	else{
		var-=5;
		printf("Inside Parent Process\n");
		printf("Modified value is %d",var);
	}
return 0;
}
