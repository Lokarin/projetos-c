#include <stdio.h>
#include <string.h>

char string[5] = "cois"; 

int main () {
	printf("Original: %s\n",string);
	fgets(string, sizeof(string), stdin);
	printf("Alterado: %s",string);
	return 0;
}
