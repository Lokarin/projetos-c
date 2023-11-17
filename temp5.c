#include <stdio.h>
#include <stdlib.h>

float parcela, resultado = 0;
int dias = 0;
int controle = 1;

float valor_pago(float a, int b) {
	float valor = 0;

	if (dias == 0) {
		valor = a;
	} else {
		valor = a + (a*0.03) + b*(a*0.01);
	}

	return valor;
}

int main() {
	while (controle == 1) {
		printf("Valor da parcela: ");
		scanf("%f",&parcela);
		printf("Dias em atraso: ");
		scanf("%i",&dias);

		resultado = valor_pago(parcela, dias);
		printf("Valor a ser pago: R$ %.2f\n\n",resultado);

		printf("Continuar processo?\n\
	- 1: Sim\n\
	- 0: Nao\n\
Resposta: ");	
		scanf("%i",&controle);
	}

	return 0;
}
