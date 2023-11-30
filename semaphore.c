#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>
#define WORK_SIZE 1024
void *thread_function(void *arg);
char work_area[WORK_SIZE];
sem_t bin_sem;
int main(){
	int res;
	pthread_t a_thread;
	void *thread_result;
	res=sem_init(&bin_sem,0,0);
	if(res!=0){
		perror("Semaphore Initialization failed\n");
		exit(EXIT_FAILURE);
	}
	res=pthread_create(&a_thread,NULL,thread_function,NULL);   //For creating threads or part of process for execution
	if(res!=0){
		perror("Thread Creation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Input some text.End 'end' to finish\n");
	while(strncmp("end",work_area,3)!= 0){
		fgets(work_area,WORK_SIZE,stdin);
		sem_post(&bin_sem);
	}
	printf("\nWaiting for thread to finish...\n");
	res=pthread_join(a_thread,&thread_result);   //Help a process to terminate
	if(res!=0){
		perror("Thread Join failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Thread Joined\n");
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);
}
void *thread_function(void *arg){
	sem_wait(&bin_sem);
	while(strncmp("end",work_area,3)!= 0){
		printf("You input %d characters\n",strlen(work_area)-1);
		sem_wait(&bin_sem);
	}
	pthread_exit(NULL);
}

