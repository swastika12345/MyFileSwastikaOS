#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t child_pid;
	child_pid=fork();
	if(child_pid == 0){
		printf("Child process with PID %d is running\n",getpid());
		sleep(2);
		printf("Child process with PID %d is done\n",getpid());
	}
        else if(child_pid>0){
		printf("Parent process with PID %d is waiting for the child\n",getpid());
		int status;
		pid_t terminated_child_pid=wait(& status);
		if(terminated_child_pid > 0){
 		if(WIFEXITED(status)){
				printf("Child process with PID %d has terminated normally with status %d\n",terminated_child_pid,WEXITSTATUS(status));
			}
		else if(WIFSIGNALED(status)){
			printf("Child process with PID %d has terminated due to signal %d\n",terminated_child_pid,WTERMSIG(status));
		}
		}
	}
	else{
		printf("fORK failed");
		exit(1);
	
	}
return 0;
}
