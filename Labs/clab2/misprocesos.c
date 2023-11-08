#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void Usage(){
	char buff[64];
	sprintf(buff,"Cal introduir 2 arguments\n");
	write(1,buff,strlen(buff));
	exit(1);
}

int main (int argc, char *argv[]) {
if( argc != 2) Usage();
int fd[2];
char buffer[258];
if (pipe(fd)<0) {
	perror("Error en la creació de la pipe");
	exit(1);
}
int pid = fork();
if (pid==0){
	int a = open(argv[1],O_CREAT|O_TRUNC|O_WRONLY, S_IRWXU);
	if (a<0) {
		perror("Error open arxiu");
		exit(1);
	}
	close(0);
	dup(fd[0]);
	close(1);
	dup(a);
	close(fd[0]);
	close(fd[1]);
	execlp ("grep","grep", "-v", "TIME", (char*)NULL);
	perror("Error en la mutacio");
	exit(1);
}
else if (pid < 0) {
	perror("Error en el fork");
	exit(1);
}
else {
	close(1);	
	dup(fd[1]);
	close(fd[0]);
	close(fd[1]);
	execlp ("ps","ps", "-l", (char*)NULL);
	perror("Error en la mutacio");
	exit(1);
}
}
