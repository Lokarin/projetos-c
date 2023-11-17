#include <stdio.h>
#include <stdlib.h>
#include "temp.h"
#include <math.h>

int main(){
	eqSegundoGrau(1, 5, -25);
	return 0;
}

void eqSegundoGrau(float a, float b, float c){
	float delta = 0;
	double r1, r2 = 0;

	delta = pow(b,2) - 4*a*c;

	if (delta > 0) {
		r1 = (-b + sqrt(delta)) / (2 * a);
		r2 = (-b - sqrt(delta)) / (2 * a);

		printf("X1 = %f e X2 = %f\n",r1,r2);

	} else if (delta == 0) {
		r1 = r2 = -b / (2 * a);

		printf("Apenas uma raiz: %f\n",r1);

	} else {
		puts("Sem raizes reais.");

	}
}
