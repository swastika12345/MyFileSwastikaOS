#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main(){
	printf("I am the Parent Process\n");
	char *arg_Ptr[4];
	arg_Ptr[0]="childEXECV.c";
	arg_Ptr[1]="Hello from the child Process";
	arg_Ptr[2]="Godbye from the Child Process!";
	arg_Ptr[3]="OS Lab Asssignment 5";
	execv("Cexecv",arg_Ptr);
	printf("Error :%i\n",errno);
}
