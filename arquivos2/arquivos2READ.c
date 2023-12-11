#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *arq;
	char c;
	arq = fopen("/home/lokarin/IFSC/sem4/PROG/projetosC/arquivos2/teste.txt","r");

	if (arq == NULL) {
		puts("Falha na abertura do arquivo");
		system("pause");
		exit(1);
	}

	while ((c = fgetc(arq)) != EOF) {
		printf("%c",c);
	
	}

	fclose(arq);
	
	return 0;
}
