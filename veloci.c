#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float vel, res = 0;

float multa(float a) {
	float r = 0;

	if (a <= 50) {
		puts("\nAte Velocidade permitida.");	
	} if (a > 50 & a <= 55) {
		puts("\nAte 10% fora do limite.");
		r = 230;
	} if (a > 55 & a <= 60) {
		puts("\nAte 20% fora do limite.");
		r = 340;
	} if (a > 60) {
		puts("\nMais de 20% fora do limite.");
		r = (a-50)*19.28;
	
	}
	return r;
}

int main () {
	printf("Velocidade: ");
	scanf("%f",&vel);

	res = multa(vel);
	if (res == 0) {
		puts("Sem Multa");
	
	} else {
		printf("Multa: R$ %.2f\n",res);
	}

	return 0;
}
