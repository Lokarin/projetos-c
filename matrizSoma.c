#include <stdio.h>
#include <stdlib.h>

int a[2][2], b[2][2], c[2][2];

int main() {
	for (int i = 0; i<2; i++) {

		for (int j = 0; j<2 ; j++) {
			printf("Numero a(%i,%i) = ",i,j);
			scanf("%i",&a[i][j]);
		}
	}
	printf("%i %i\n\
%i %i\n",a[0][0],a[0][1],a[1][0],a[1][1]);

	for (int i = 0; i<2; i++) {

		for (int j = 0; j<2 ; j++) {
			printf("Numero b(%i,%i) = ",i,j);
			scanf("%i",&b[i][j]);
		}
	}
	printf("%i %i\n\
%i %i\n",b[0][0],b[0][1],b[1][0],b[1][1]);

	for (int i = 0; i<2; i++) {

		for (int j = 0; j<2 ; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	printf("%i %i\n\
%i %i\n",c[0][0],c[0][1],c[1][0],c[1][1]);

	return 0;
}
