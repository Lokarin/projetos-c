#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *arq;
	char string[100];
	int i;
	arq = fopen("/home/lokarin/IFSC/sem4/PROG/projetosC/arquivos2/teste.txt","w");

	if (arq == NULL) {
		puts("Falha na abertura do arquivo");
		system("pause");
		exit(1);
	}
	printf("string: ");
	fgets(string, sizeof(string), stdin);

	for (i = 0; i < strlen(string); i++) {
		fputc(string[i],arq);
	}

	fclose(arq);
	
	return 0;
}
