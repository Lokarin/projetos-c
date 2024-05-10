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

struct pilha {
	No *topo;
	int tam;
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

void criaPilha(Pilha *p){
	p->tam = 0;
	p->topo= NULL;
}

void empilhar(Pilha *p) {
	No *novo = calloc(1, sizeof(No));

	if (novo) {
		novo->c = criar_carro();
		novo->proximo = p->topo;

		p->topo = novo;
		p->tam++;
	} else {
		puts("\nFalha ao alocar memoria.");
	}
}

No *desemplilhar(Pilha *p) {
	if (p->topo) {
		No *remover = p->topo;
		p->topo = remover->proximo;
		p->tam--;
		return remover;
	} else {
		puts("\nPilha ja esta vazia");
	}
	return NULL;
}

void imprimirPilha(Pilha *p) {
	No *aux = p->topo;
	puts("\n---==+ Pilha +==---");
	while (aux) {
		printDados(aux->c);
		aux = aux->proximo;
	}
	puts("---==+ END +==---");
}

void menu() {
	No *remover = NULL;
	Pilha p;
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
				empilhar(&p);
			break;
			case 2:
			remover = desemplilhar(&p);
			if (remover) {
				puts("\nRemovido com sucesso");
				printDados(remover->c);

				free(remover);
			} else {
				puts("Sem elementos para remover");
			}
			break;
			case 3:
				imprimirPilha(&p);
			break;
			default:
			if (x !=0) {
				puts("Invalido");
			}
		}
	}
}
