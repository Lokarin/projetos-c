# include "stdio.h"
# include <stdlib.h>

int nascimento = 0;
int idade = 0;

int main() {
	// Nascimento
	printf("Ano de nascimento: ");
	scanf("%i",&nascimento);
	printf("-----------------// \n\n");

	// Idade
	idade=2050-nascimento;

	printf("Idade em 2050: %i\n",idade);

	return 0;
}
