#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void oh(int sig){
        printf("OH!-I got signal %d\n",sig);
        signal(SIGINT,oh);
        //signal(SIGQUIT,oh);
        //signal(SIGQUIT,SIG_DFL);
}
int main(){
        signal(SIGSTOP,oh);
        while(1){
                printf("Hello World!\n");
                sleep(1);
        }
}

