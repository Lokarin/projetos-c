#include <stdio.h>

#include "aplicacao.h"

int main() {
	Jogador *jogador1 = criaJogador();

	menu(jogador1);

	freeTudo(jogador1);
	return 0;
}
