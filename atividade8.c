#include "stdio.h"
#include <string.h>

int i = 0;
char x[4] = "sim";

int main() {
	while (strcmp(x, "sim")) {
		printf("Mais pessoas? (sim/nao): ");
		scanf("%c",&x[4]);
	
	}
	
	return 0;
}
