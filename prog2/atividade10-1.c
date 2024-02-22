#include <stdio.h>
#include <stdlib.h>

void reorder(int *x) {
	int temp = 0;
	
	puts("Numeros iniciais: ");
	for (int i = 0; i < 3; i++) {
		printf("%c: %i\n",('a'+i),x[i]);
	
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x[j]>x[i]) {
				temp = x[i];
				x[i] = x[j];
				x[j] = temp;
			}
		}
	}
	
	puts("Numeros finais: ");
	for (int i = 0; i < 3; i++) {
		printf("%c: %i\n",('a'+i),x[i]);
	
	}
}

int main() {
	int valores[3];

	for (int i=0; i<3; i++) {
		printf("Valor de %c: ",'a'+0);
		scanf("%i",&valores[i]);
	}

	reorder(valores);

	return 0;
}
