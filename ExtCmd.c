#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
	FILE *write_fp;
	char buffer[BUFSIZ +1];
	sprintf(buffer,"OS Lab Assignment 9\n");
	write_fp=popen("cat > newfile.txt","w");
	if(write_fp!=NULL){
		fwrite(buffer,sizeof(char),strlen(buffer),write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
return 0;
}
