#include <stdio.h>
#include <stdlib.h>

#include "implementacao.h" 

struct matrizes {
	float **m1;
	float **m2;
	float **res;
};

//Funcao para criar struct
Matrizes *criarMatriz(int n) {

	// Aloca Struct
	Matrizes *a = (Matrizes*)calloc(1, sizeof(Matrizes));

	// Aloca Linhas de m1
	a->m1 = calloc(n, sizeof(float *));

	// Aloca Linhas de m2
	a->m2 = calloc(n, sizeof(float *));

	// Aloca Linhas de res
	a->res = calloc(n, sizeof(float *));

	// Aloca Colunas de m1
	for (int i = 0; i < n; i++) {
		a->m1[i] = calloc(n,sizeof(float));
	}

	// Aloca Colunas de m2
	for (int i = 0; i < n; i++) {
		a->m2[i] = calloc(n,sizeof(float));
	}

	// Aloca Colunas de res
	for (int i = 0; i < n; i++) {
		a->res[i] = calloc(n,sizeof(float));
	}

	return a;
}

// Preencher m1
void preencherMatrizM1(Matrizes *a, int n) {
	puts("\n---=+Preencher Matriz 1 +=---");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("Valor em m1[%i][%i]: ",i,j);
			scanf("%f",&a->m1[i][j]);
		}
	}
}

// Preencher m2
void preencherMatrizM2(Matrizes *a, int n) {
	puts("\n---=+Preencher Matriz 2 +=---");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("Valor em m2[%i][%i]: ",i,j);
			scanf("%f",&a->m2[i][j]);
		}
	}
}

// Soma matrizes
void somaMatrizes(Matrizes *a, int n) {
	// Resultado = m1 + m2
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a->res[i][j] = a->m1[i][j] + a->m2[i][j];
		}
	}

	printResult(a, n);
}

void multiMatrizes(Matrizes *a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a->res[i][j] = 0;
			
			for (int k = 0; k < n; k++) {
				a->res[i][j] += a->m1[i][k] * a->m2[k][j];
			}
		}
	}

	printResult(a, n);
}

// Print resultados
void printResult(Matrizes *a, int n) {
	puts("");
	for (int i = 0; i< n; i++) {
		printf("|");
		for (int j = 0; j < n; j++) {
			printf("\t%.2f\t",a->m1[i][j]);
		}

		printf("|    +    |");

		for (int j = 0; j < n; j++) {
			printf("\t%.2f\t",a->m2[i][j]);
		}

		printf("|    =    |");

		for (int j = 0; j < n; j++) {
			printf("\t%.2f\t",a->res[i][j]);
		}

		puts("|");
	}
}

// Menu
void menu() {
	int x = 9, n = 0;
	Matrizes *a; 

	while (x != 0) {
		printf("Voce deseja somar ou multiplicar estas matrizes:\n\
		1 - Somar\n\
		2 - Multiplicar\n\
		0 - Sair do progama\n\
Opcao: "	);
		scanf("%i",&x);


		switch (x) {
			case 1:
				// Definir tamanho da matriz
				printf("Numero de linhas/colunas das matrizes quadradas: ");
				scanf("%i",&n);

				// Cria matriz
				a = criarMatriz(n);

				// Preencher
				preencherMatrizM1(a, n);
				preencherMatrizM2(a, n);

				// Chama operacao
				somaMatrizes(a, n);

				freeMatrizes(a, n);
			break;
			case 2:
				// Definir tamanho da matriz
				printf("Numero de linhas/colunas das matrizes quadradas: ");
				scanf("%i",&n);

				// Cria matriz
				a = criarMatriz(n);

				// Preencher
				preencherMatrizM1(a, n);
				preencherMatrizM2(a, n);

				// Chama operacao
				multiMatrizes(a, n);

				freeMatrizes(a, n);
			break;
			case 0:
			break;
		}
	}
}

// Free struct e componentes
void freeMatrizes(Matrizes *a, int n) {
	for (int i = 0; i < n; i++) {
		free(a->m1[i]);
	}
	free(a->m1);

	for (int i = 0; i < n; i++) {
		free(a->m2[i]);
	}
	free(a->m2);

	for (int i = 0; i < n; i++) {
		free(a->res[i]);
	}
	free(a->res);

	free(a);

	puts("\nFree completo");
}
