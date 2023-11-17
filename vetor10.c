#include <stdio.h>
#include <stdlib.h>

int vetor[10];

int main() {
	for (int i = 0; i < 10; i++) {
		scanf("%i",&vetor[i]);
	}

	printf("(");
	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			printf("%i)",vetor[i]);
		}else {
			printf("%i, ",vetor[i]);
		}
	
	}
	printf(")");

	return 0;
}
