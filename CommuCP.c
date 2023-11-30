#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	int data_processed;
	int file_pipes[2];
	const char some_data[]="Swastika Kayal";
	char buffer[BUFSIZ +1];
	pid_t fork_result;
	memset(buffer,'\0',sizeof(buffer));
	if(pipe(file_pipes) == 0){
		fork_result=fork();
		if(fork_result ==-1){
			fprintf(stderr,"Fork failure");
			exit(EXIT_FAILURE);
		}
	else if(fork_result == 0){
		sleep(2);
		data_processed=read(file_pipes[0],buffer,BUFSIZ);
		printf("Child read %d bytes: %s\n",data_processed,buffer);
		exit(EXIT_SUCCESS);	
	}
	else{
		data_processed=write(file_pipes[1],some_data,strlen(some_data));
		printf("parent wrote %d bytes :%s\n",data_processed,some_data);
	}
	
}
exit(EXIT_SUCCESS);
}
