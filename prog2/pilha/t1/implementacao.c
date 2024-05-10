# include <stdio.h>
# include <stdlib.h>

# include "implementacao.h"

struct carro{
	char nome[20];
	char cor[10];
};

struct no {
	Carro c;
	No *proximo;
};

Carro criar_carro() {
	Carro c;

	fgetc(stdin);
	printf("Nome do carro: ");
	fgets(c.nome, 20, stdin);
	printf("Cor do carro: ");
	fgets(c.cor, 10, stdin);

	return c;
}

void printDados(Carro c) {
	printf("O carro %s ",c.nome);
	printf("tem cor %s\n",c.cor);
}

No *empilhar(No *topo) {
	No *novo = calloc(1, sizeof(No));

	if (novo) {
		novo->c = criar_carro();
		novo->proximo = topo;
		return novo;
	} else {
		puts("\nFalha ao alocar memoria.");
	}
	return NULL;
}

No *desemplilhar(No **topo) {
	if (*topo != NULL) {
		No *remover = *topo;
		*topo = remover->proximo;
		return remover;
	} else {
		puts("\nA pilha esta vazia");
	}

	return NULL;
}

void imprimirPilha(No *topo) {
	puts("\n---==+ Pilha +==---");
	while (topo) {
		printDados(topo->c);
		topo = topo->proximo;
	}
	puts("---==+ END +==---");
}

void menu() {
	No *topo, *remover = NULL;
	int x = 9;

	while (x != 0) {
		printf("\nSelecione uma opcao:\n\
1 - Empilhar\n\
2 - Desempilhar\n\
3 - Imprimir pilha\n\
0 - Sair\n\
Opcao: ");
		scanf("%i",&x);

		switch (x) {
			case 1:
				topo = empilhar(topo);
			break;
			case 2:
			remover = desemplilhar(&topo);
			if (remover) {
				puts("\nRemovido com sucesso");
				printDados(remover->c);

				free(remover);
			} else {
				puts("Sem elementos para remover");
			}
			break;
			case 3:
				imprimirPilha(topo);
			break;
			default:
			if (x !=0) {
				puts("Invalido");
			}
		}
	}
}
