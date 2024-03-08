#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "aplicacao.h"

struct jogador {
	char *nome;
	float jogos;
	float gols;
	float assistencias;
};

Jogador *criaJogador() {
	Jogador *a = (Jogador*)calloc(1, sizeof(Jogador));

	printf("Nome do jogador: ");
	a->nome = stringAlocada();

	printf("Quantos jogos jogados: ");
	scanf("%f",&a->jogos);

	printf("Numero de gols marcados: ");
	scanf("%f",&a->gols);

	printf("Numero de assistencias: ");
	scanf("%f",&a->assistencias);

	return a;
}

// Funcao para gerar uma string alocada, https://stackoverflow.com/a/8164021
char *stringAlocada(){
	char *str, *tmp = NULL;
	size_t size, i = 0;
	int final = EOF;

	while (final) {
		final = getc(stdin);
		// Checar por final de input
		if (final == EOF || final == '\n') {
			final = 0;
		}

		// Alocar tamanho de str
		if (size <= i) {
			size += sizeof(char);
			tmp = realloc(str, size);
			if (!tmp) {
				free(str);
				str = NULL;
				break;
			}
			str = tmp;
		}
		// Guardar input em str
		str[i++] = final;
	}

	return str;
}

void printValores(Jogador *a) {
	printf("\nInformacoes de %s:\n",a->nome);
	printf(" -Jogos: %.2f\n",a->jogos);
	printf(" -Gols: %.2f\n",a->gols);
	printf(" -Assistencias: %.2f\n",a->assistencias);
}

void ehBom(Jogador *a) {
	float bom = (a->gols + a->assistencias) / a->jogos;

	printf("\nEsse jogador tem %.2f gols/assistencias por jogo\n",bom);
	if (bom >= 1) {
		puts("Esse cara eh bom");
	}
}

void preencher(Jogador *a) {
	printf("Quantos jogos jogados: ");
	scanf("%f",&a->jogos);

	printf("Numero de gols marcados: ");
	scanf("%f",&a->gols);

	printf("Numero de assistencias: ");
	scanf("%f",&a->assistencias);
}

void menu(Jogador *a) {
	int escolha = 3;

	while (escolha !=0) {
		printf("\nOque voce deseja fazer?\n\
	1 - Alterar informacoes do jogador;\n\
	2 - Verificar informacoes do jogador;\n\
	3 - Verificar a participacao de gols p/ jogo do jogador;\n\
	0 - Encerrar progama.\n\
Opcao: ");
		scanf("%i",&escolha);
		
		switch (escolha) {
			case 1:
				preencher(a);
			break;
			case 2:
				printValores(a);
			break;
			case 3:
				ehBom(a);
			break;
			case 0:
			break;
		}
	}
}

void freeTudo(Jogador *a) {
	free(a);
	a->nome = NULL;
	a = NULL;
}
