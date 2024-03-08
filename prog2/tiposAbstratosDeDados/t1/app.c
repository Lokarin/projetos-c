#include <stdio.h>
#include "implementacao.h"

int main() {
	int n = 0;

	printf("Numero de linhas/colunas das matrizes quadradas: ");
	scanf("%i",&n);

	Matrizes *a = criarMatriz(n);
	preencherMatrizM1(a, n);
	preencherMatrizM2(a, n);

	somaMatrizes(a, n);


	freeMatrizes(a, n);
	return 0;
}
