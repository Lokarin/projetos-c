#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float indutancia, diametro, corrente, awg = 0;
int camada = 0;

// Area e diametro do cobre
float bitola(float corrente) {
	// Calculo da area e diametro di cobre
	float area = (corrente / 1000) / 420;
	printf("\nArea do Cobre: %f cm²\n",area);

	float diametroCobre = (sqrt((area / M_PI))) * 2;
	printf("Diametro do Cobre: %f\n",diametroCobre);

	return 0;
}

// Calcular eq de segundo grau
float eqSegundoGrau(float indutancia, float diametro, float awg, int camada){
	double a, b, c, r1, r2, delta, l;

	// coeficientes
	a = 31.6 * ((diametro / 200) * (diametro / 200));
	b = (-9 * (awg / 100) * indutancia) / camada;
	c = (-6 * (diametro / 200) * indutancia) + (-10 * ((awg * camada) / 100) * indutancia);

	//printf("a: %f\n",a);
	//printf("b: %f\n",b);
	//printf("c: %f\n",c);

	// calculo de delta
	delta = b*b - 4*a*c;

	//printf("\ndelta: %f\n",delta);

	// calculo das raizes e comprimento da bobina
	if (delta > 0){
		r1 = roundf((-b + sqrt(delta)) / (2 * a));
		r2 = roundf((-b - sqrt(delta)) / (2 * a));

		//printf("%.2f",r1);
		//printf("%.2f",r2);

		if (r1 > 0) {
			printf("\n%.2f espiras, ",r1);
			l = (r1 / camada) * (awg / 100); 
			printf("%.4f metros de comprimento\n",l);
		}
		if (r2 > 0) {
			printf("\n%.2f espiras\n",r2);
			l = (r2 / camada) * (awg / 100); 
			printf("%.4f metros de comprimento\n",l);
		}

	} else if (delta == 0) {
		r1 = r2 = roundf(-b / (2 * a));

		if (r1 > 0) {
			printf("\n%.2f",r1);
			l = (r1 / camada) * (awg / 100); 
			printf("%.4f metros de comprimento\n",l);
		}
	} else {
		printf("Sem raizes reais");
		printf("\ndelta: %f\n",delta);
	}
	
	return 0;
}

int main() {
	// Coleta dos dados
	printf("Indutancia Nominal (uH): ");
	scanf("%f",&indutancia);
	printf("Diametro interno (cm): ");
	scanf("%f",&diametro);
	printf("Numero de Camadas: ");
	scanf("%i",&camada);
	printf("Corrente maxima (mA): ");
	scanf("%f",&corrente);

	// Valores para serem comparados com tabela AWG
	bitola(corrente);

	printf("\nCom base na tabela de fios esmaltados, qual o diametro\n\
do fio COM isolamento mais proximo dos valores acima? (cm): ");
	scanf("%f",&awg);

	// Encontrar n de espiras e comprimento da bobina
	eqSegundoGrau(indutancia, diametro, awg, camada);

	return 0;
}
