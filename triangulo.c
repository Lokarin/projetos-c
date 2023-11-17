#include <stdio.h>
#include <stdlib.h>

int j, k = 0;

int main() {
	for (int i = 0; i <= 7; i++) {
		for (j; j < 7 - i; j++) {
			printf(" ");
		}
		j = 0;

		for (k; k <= i; k++) {
			printf("*");
		}
		k = 0;
		printf("\n");
	}
}
