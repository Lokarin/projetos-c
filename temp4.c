#include <stdio.h>
#include <stdlib.h>

float bomba = 0;

void calculo(float a) {
	float dr, cea, icms, cide = 0;
	
	dr = a * 0.17;
	cea = a * 0.12;
	icms = a * 0.28;
	cide = a * 0.07;  

	printf("+ Valor na bomba: R$ %.2f\n",bomba);
	printf("- Distribuicao e Revenda (17%%): R$ %.2f\n",dr);
	printf("- Custo Etanol Anidro (12%%): R$ %.2f\n",cea);
	printf("- ICMS (28%%): R$ %.2f\n",icms);
	printf("- CIDE, PIS/PASEP e COFINS: (7%%) R$ %.2f\n",cide);
	printf("= Valor da refinaria: R$ %.2f\n",bomba-dr-cea-icms-cide);
}

int main() {
	printf("Valor do combustivel na bomba: ");
	scanf("%f",&bomba);

	calculo(bomba);

	return 0;
}
