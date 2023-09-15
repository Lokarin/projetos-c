# include <stdio.h>
# include <stdlib.h>

float deposito = 0;
float taxa = 0;
int meses = 0;
int tempo = 0;

int main() {
	// Deposito
	printf("Valor do deposito: ");
	scanf("%f",&deposito);
	// Taxa
	printf("Valor da taxa: ");
	scanf("%f",&taxa);
	// Meses
	printf("Quantos meses ate saque: ");
	scanf("%i",&meses);

	while (meses>0) {
		meses--;
		tempo++;
		printf("Mes: %02d \n \n",tempo);
	}


	//printf("%.2f \n",deposito);
	//printf("%.2f \n",taxa);
	return 0;
}
