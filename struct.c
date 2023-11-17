#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
	int id;
	float nota;
} Aluno;

Aluno alunoInfo() {
	Aluno x;

	printf("ID: ");
	scanf("%i",&x.id);
	printf("Nota: ");
	scanf("%f",&x.nota);
	printf("\n");

	return x;
}

void leDados(Aluno x) {
	printf("ID: %i\n",x.id);
	printf("Nota: %.2f\n",x.nota);
}

int main() {
	Aluno p = alunoInfo();
	leDados(p);

	return 0;
}
