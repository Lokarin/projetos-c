#include <stdio.h>
#include <stdlib.h>

float a, b, r, resultado = 0;
int controle = 1;
int escolha = 0;

float opera(int op, float n1, float n2) {
	switch (op) {
		case 1:
			r = n1 + n2;
		break;
		case 2:
			r = n1 - n2;
		break;
		case 3:
			r = n1 * n2;
		break;
		case 4:
			r = n1 / n2;
		break;
	}
	return r;
}

int main() {
	while (controle != 5) {
		printf("\nOperacao Realizada entre N1 e N2:\n\
	1 - Adicao\n\
	2 - Subtracao\n\
	3 - Multiplicacao\n\
	4 - Divisao\n\
	5 - Encerrar\n\
Escolha: ");
		scanf("%i",&escolha);

		if (escolha == 5) {
			break;
		} else {
			printf("\nValor de N1: ");
			scanf("%f",&a);
			printf("Valor de N2: ");
			scanf("%f",&b);

			resultado = opera(escolha, a, b);
			printf("\nResultado: %.2f\n",resultado);
		}
	}
	return 0;
}
