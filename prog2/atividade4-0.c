#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto2D {
	float x;
	float y;
} Ponto2D;

typedef struct corRGB {
	int R;
	int G;
	int B;
} CorRGB;

typedef struct quadrilatero {
	Ponto2D vA;
	Ponto2D vB;
	Ponto2D vC;
	Ponto2D vD;
	CorRGB cor;
} Quadrilatero;

float calcArea(Quadrilatero *x) {
	float area = 0.5 * ((x->vA.x*x->vB.y)+(x->vB.x*x->vC.y)+(x->vC.x*x->vD.y)-(x->vB.x*x->vA.y)-(x->vC.x*x->vB.y)-(x->vD.x*x->vC.y)-(x->vA.x*x->vC.y));
	return area;
}

int main() {
	Quadrilatero quad;

        //pA
	puts("Ponto A: ");
	printf("x: ");
	scanf("%f",&quad.vA.x);
	printf("y: ");
	scanf("%f",&quad.vA.y);
        //pB
	puts("\nPonto B: ");
	printf("x: ");
	scanf("%f",&quad.vB.x);
	printf("y: ");
	scanf("%f",&quad.vB.y);
        //pC
	puts("\nPonto C: ");
	printf("x: ");
	scanf("%f",&quad.vC.x);
	printf("y: ");
	scanf("%f",&quad.vC.y);
        //pD
	puts("\nPonto D: ");
	printf("x: ");
	scanf("%f",&quad.vD.x);
	printf("y: ");
	scanf("%f",&quad.vD.y);
        //RGB
	puts("\nRGB: ");
	printf("R: ");
	scanf("%i",&quad.cor.R);
	printf("G: ");
	scanf("%i",&quad.cor.G);
	printf("B: ");
	scanf("%i",&quad.cor.B);

	float result = calcArea(&quad);
	printf("Resultado da area: %f",result);

	return 0;
}
