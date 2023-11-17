#include <stdio.h>

int x, y;

int main () {
	x = 1;
	y = 2;

	printf("%i\n",x&y);
	printf("%i\n",x&&y);

	if (x==1 & y==2) {
		printf("\n& funcionou\n");
	}

	if (x==1 && y==2) {
		printf("&& funcionou\n");
	}
}

// && passa por todas condicoes independente do resultado da
// primeira.
