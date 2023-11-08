#include <unistd.h>
#include <string.h>
#include <stdio.h>

main(){
	int numero;
	char buff[128];
	read(0, &numero, sizeof(int));
	sprintf(buff, "%i\n", numero);
	write (0, buff, strlen(buff));
}
