_____________________________PLANTILLA__________________________________

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
#include "socketMng.c"

int main (argc, agrv[]) {

}
_______________________________BASICS___________________________________

int pid = fork();
	pare: pid fill
	fill: 0
	error: <0
switch (pid) {
		case 0: /* FILL */ 
			....
			exit(0);
		case -1:
			sprintf(buffer,"Error\n");
			write(1, buffer, strlen(buffer));
			exit(1);
		default: /* Pare */
			...
			exit(0);
}
getpid();

sprintf(buffer,"hola hola aixo es un numero %d\n", num);
strcpy(buffer, "Read correcto:\n");

i = atoi(char);

int res;
int pid=waitpid(-1,&res,0);
if (WIFEXITED(res) != 0 )    Proces pid acaba amb exit(WEXITSTATUS(res))
else     Proces acaba amb signal amb codi : WIFSIGNALED(res)

if (pid=waitpid(-1,NULL,WNOHANG))
	torna inmediatament si no cap fill zombie

ps (-e) //veure processos
strace ./exec // veure crides al sistema que fa

lsmod //veure divers instalats

_______________________________SIGNALS__________________________________

void funcion_alarma(int s) {
    if(s == SIGALRM) ....
    else ...
}

signal(SIGALRM,funcio);      alarma
signal(SIGUSR1,funcio);      disponible
signal(SIGSEGV,funcio);      segmentation fault

alarm(segons);
	retorna segons que queden ultima alarma o 0

_______________________________MUTACIO__________________________________

execlp ("./nom","nom", "par1", ...., NULL);

_______________________________MEMORIA__________________________________

int *s = malloc(sizeof(int));
int *vector;
vector = sbrk(n * sizeof(int));
vector apuntador a primera pos, vector++ per avançar
free(p);
if (p == NULL) error en malloc o sbrk
sbrk(0) retorna primera pos memoria que no utilitzem

Address: &p
p value: *p

_______________________________INFO_____________________________________

objdump nom_exec
nm nom_exec

/proc/cpuinfo
/proc/[pid]/
	maps
	...

__________________________ENTRADA/SORTIDA_______________________________


comandes (mknod, insmod, rmmod, sudo, lsmod, open, read, grep, ps, 
strace, siginterrupt, socket, bind, listen, accept, connect)

ls –l > salida //escribim sortida a salida
grep es < salida //te com a entrada salida
ls -l | grep es

ret = read (0, &buff, sizeof(buff));
	ret == 0 no queda res per llegir
write (1, buff, strlen(buff));

int utilitzant representació interna
	int num=10562;
	write(1,&num,sizeof(int));
	
representació interna a int
	read(0, &numero, sizeof(int));
	sprintf(buff, "%i\n", numero);
	write (1, buff, strlen(buff));

int fd = open(“datos.txt”,O_RDONLY);
read(fd,&num,sizeof(int));

opcions:
	O_RDONLY
	O_WRONLY
	O_RDWR

fd = open ("fitxer.txt", O_RDONLY);
	error si fd <0;
	read(fd, buffer, strlen(buffer));

PIPE sense nom
	int fd[2];
	pipe(fd);
	extrem lectura fd[0]
	extrem escritura fd[1]

PIPE amb nom
	# mknod pipe1 p
	fd = open("pipe1", O_WRONLY);
	
dup2(1, x) substituim el canal 1 per x
dup(x) substituim el fd mes petit lliure per x
close(x);

Sockets...

lseek(fd, int, SEEK_SET);
SEEK_SET The file offset is set to offset bytes.
SEEK_CUR The file offset is set to its current location plus offset
SEEK_END The file offset is set to end plus offset bytes.

________________________SISTEMA_DE_FITXERS______________________________
	
comandes (open/creat, df, ln, namei, readlink, stat, lseek)
df info sistema fitxeer (-T, -h, -l, -i)
ln enllaços a fitxers -s
ln Crea enlaces (links) a ficheros
namei Procesa una ruta de un fichero hasta encontrar el punto final
readlink Lee el contenido de un link simbólico
stat Muestra información de control de un fichero
lseek modifica posicio de lectura /escriptura en un fitxer

crear fitxer int fd = creat("salida.txt", O_RDWR);

exemples links 
$ echo “estoy en el directorio A” > D 
$ ln -s $HOME/A $HOME/A/E
$ ln -s D $HOME/A/F
$ ln $HOME/A $HOME/A/H
$ ln D $HOME/A/G

stat more cat i readlink!!!

