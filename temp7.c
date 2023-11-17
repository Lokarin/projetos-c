#include <stdio.h>
#include <stdlib.h>

char p[30] = "";

int main() {
	fgets(p, 30, stdin);
	printf("%s",p);
}
