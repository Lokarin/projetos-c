# include <stdio.h> 
# include <stdlib.h>

float salario = 0;
float salario2 = 0;
float aumento = 0;
float aumento2 = 0;

int main() {
	// Salario
	printf("Valor do salario: ");
	scanf("%f",&salario);
	// Aumento
	printf("Porcentagem do aumento: ");
	scanf("%f",&aumento);
	printf("-----------------// \n\n");

	// Aumento do salario
	aumento2=salario*(aumento/100);

	// Salario final
	salario2=salario+aumento2;

	printf("Aumento do salario: %.2f \n",aumento2);
	printf("Salario final: %.2f \n",salario2);

	return 0;
}
