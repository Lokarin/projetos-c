#include <stdio.h>
#include <stdlib.h>

void troca(int *px, int *py) {
	int temp;
	temp = *py;
	*py = *px;
	*px = temp;
}

int main() {
	int a, b;
	
	a = 2;
	b = 3;

	printf("%d %d\n",a,b);

	troca(&a, &b);

	printf("%d %d\n",a,b);

	return 0;
}
