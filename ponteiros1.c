#include <stdlib.h>
#include <stdio.h>

void inr_vetor(int *v) {

	for (int i; i < 3; i++) {
		v[i]++;
	}

	for (int i; i < 3; i++) {
		printf("%d ",v[i]);
	
	}
	printf("\n");
}

int main() {
	int a[] = {1,3,6};
	inr_vetor(a);

	return 0;
}
