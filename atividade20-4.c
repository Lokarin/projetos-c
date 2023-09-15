#include <stdio.h>
#include <stdlib.h>

int num[] = {7,2,4,11,10};
int temp = 0;
int tamanho = sizeof(num)/sizeof(num[0]);

int main() {
	for (int i = 0; i < tamanho; i++) {
		printf("%i, ",num[i]);
	}
	printf("\n");

	for (int i = 0; i < tamanho; i++) {
		for (int a = i+1; a < tamanho; a++) {
			if (num[i] > num[a]) {
				temp = num[i];
				num[i] = num[a];
				num[a] = temp;
			}
		}
	}

	for (int i = 0; i < tamanho; i++) {
		printf("%i, ",num[i]);
	}
	printf("\n");

	return 0;
}
