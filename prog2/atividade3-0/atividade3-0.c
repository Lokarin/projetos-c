#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCHAR 1000

typedef struct meteoro {
	int hora;
	int minuto;
	float tcelsius; 
	float pammhg; 
	char local[30]; 
} Meteoro;

int linhas(FILE *x,char y[MAXCHAR]) {
	int n, p = 0;

	//feof identifica final de arquivo
	while (feof(x) != true) {
		int p = fgetc(x);

		if (p=='\n') {
			n++;
			printf("n = %i\n",n);
		}
	}
	return n;
}

int main() {
	FILE *arq;
	char coluna[MAXCHAR];
	arq = fopen("/home/lokarin/IFSC/sem5/PROG2/projetos-c/prog2/atividade3-0/dados.csv","r");
	int n = linhas(arq, coluna);
	n--;
	printf("N = %i\n",n);

	return 0;
}
