#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float n1, n2, out = 0;
int op = 0;

float oper(int op, float n1, float n2) {
	if (op == 1) {
		out = n1 + n2;
	} 
	else if (op == 2) {
		out = n1 - n2;
	}
	else if (op == 3) {
		out = n1 * n2;
	}
	else if (op == 4) {
		out = n1 / n2;
	}
	printf("%.2f \n",out);
	return 0;
}

int main() {
	// Primeiro numero
	printf("N1: ");
	scanf("%f",&n1);
	// Segundo numero
	printf("N2: ");
	scanf("%f",&n2);
	// Operacao
	printf("Operacao: \n1 - Soma\n2 - Diferenca\n3 - Multiplicacao\n4 - Divisao\nR: ");
	scanf("%i",&op);

	// Operacao
	oper(op,n1,n2);

	return 0;
}
