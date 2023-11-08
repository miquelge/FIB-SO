#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Usage(){
	char buff[64];
	sprintf(buff,"necessitem dos arguments (els dos arxius)\n");
	write(1,buff,strlen(buff));
	exit(1);
}



int main(int argc, char *argv[]){
	if( argc != 3)Usage();
	char buffer[256];
	int fd1 = open(argv[1],O_RDONLY);
	if( fd1 < 0){
	perror("error open arxiu 1");
	exit(0);
	}
	int fd2 = open(argv[2],O_RDONLY);
	if( fd2 < 0){
	perror("error open arxiu 2");
	exit(0);
	}
	int num;
	int i = 0;
	char c;
	while( (read(fd2,&num,sizeof(int))) > 0){
		lseek(fd1,num,SEEK_CUR);
		read(fd1,&c,sizeof(char));
		buffer[i++] = c;
		lseek(fd1,0,SEEK_SET);
	}
	buffer[i++] = '\n';

	write(1,buffer,strlen(buffer));
}
