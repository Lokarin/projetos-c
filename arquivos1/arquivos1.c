#include <stdio.h>
#include <stdlib.h>

int main () {
	FILE *fp;
	fp = fopen("/home/lokarin/IFSC/sem4/PROG/projetosC/arquivos1/teste.bin", "wb");

	if (fp == NULL) {
		puts("Falha na abertura do arquivo");
		system("pause");
		exit(1);
	}

	fclose(fp);

	return 0;
}
