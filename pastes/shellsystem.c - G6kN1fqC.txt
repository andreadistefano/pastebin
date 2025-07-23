#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main () {
	char comando[80];
	while(1) {
		printf("$ > ");
		fgets(comando, sizeof(comando), stdin);
                comando[strlen(comando) - 1] = '\0';
		if (strncmp(comando, "exit", 4) == 0) {
			exit(0);
		}
		else if (strncmp(comando, "cd", 2) == 0) {
			printf("%s\n", comando + 3);
			chdir(comando + 3);
		}
		else {
			system(comando);
		}
	}
	return(0);
}