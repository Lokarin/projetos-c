#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "implementacao.h"

struct aluno{
	int matricula;
	char *nome;
	float media;
};

struct noABB{
	Aluno *info;
	noABB *esq;
	noABB *dir;
};

noABB *abb_cria(){
	return NULL;
}

noABB *abb_insere(noABB *a, int mat, char *nome, float media){
	if (a == NULL) {
		noABB *aux = calloc(1, sizeof(noABB));
		if (aux == NULL) {
			puts("Erro em alocacao");
			exit(1);
		}

		aux->info = (Aluno*)calloc(1, sizeof(Aluno));
		if (aux->info == NULL) {
			puts("Erro em alocacao");
			free(aux);
			exit(1);
		}

		aux->info->nome = (char*)calloc(strlen(nome)+1, sizeof(char));
		if (aux->info == NULL) {
			puts("Erro em alocacao");
			free(aux);
			exit(1);
		}

		aux->info->matricula = mat;
		strcpy(aux->info->nome, nome);
		aux->info->media = media;

		aux->esq = NULL;
		aux->dir = NULL;

		return aux;
	} else {
		if (media < a->info->media) {
			a->esq = abb_insere(a->esq, mat, nome, media);
		} else {
			a->dir = abb_insere(a->dir, mat, nome, media);
		}
		return a;
	}
}

void abb_imprime(noABB *a){
	if (a == NULL) {
		//puts("\nArvore vazia");
		return;
	}

	if (a) {
		abb_imprime(a->esq);
		printf("\n---------------------------------");
		printf("--Nome: %s", a->info->nome);
		printf("--Matricula: %d\n", a->info->matricula);
		printf("--Media: %.2f\n", a->info->media);
		abb_imprime(a->dir);
	}
}

void abb_libera(noABB *a){
	if (a) {
		abb_libera(a->esq);
		abb_libera(a->dir);

		if (a->info && a->info->nome) {
			free(a->info->nome);
		}

		if (a->info) {
			free(a->info);
		}

		free(a);
	}
}

void abb_alunoComMaiorMedia(noABB *a){
	if (a == NULL) {
		puts("\nArvore vazia");
		return;
	}

	if (a->dir) {
		abb_alunoComMaiorMedia(a->dir);
	} else {
		puts("\n----Maior Media:");
		printf("--Nome: %s",a->info->nome);
		printf("--Matricula: %i\n",a->info->matricula);
		printf("--Media: %.2f\n",a->info->media);
	}
}

int abb_contaAprovados(noABB *a){
	if (a == NULL) {
		//puts("Arvore vazia");
		return 0;
	}

	int b = abb_contaAprovados(a->dir);

	if (a->info->media >= 6) {
		b++;
	}

	int esq = abb_contaAprovados(a->esq);
	b += esq;

	return b;
}

void abb_imprimeAprovados(noABB *a){
	if (a == NULL) {
		//puts("Arvore vazia");
		return;
	}

	abb_imprimeAprovados(a->dir);

	if (a->info->media >= 6) {
		printf("\n---------------------------------");
		printf("--Nome: %s", a->info->nome);
		printf("--Matricula: %d\n", a->info->matricula);
		printf("--Media: %.2f\n", a->info->media);
	}

	abb_imprimeAprovados(a->esq);
}

int abb_contaIntervalo(noABB *a, float min, float max){
	if (a == NULL) {
		//puts("Arvore vazia");
		return 0;
	}

	int b = 0;

	if (a->info->media >= min && a->info->media <= max) {
		b++;
	}

	if (a->info->media > min) {
		b += abb_contaIntervalo(a->esq, min, max);
	}

	if (a->info->media < max) {
		b += abb_contaIntervalo(a->dir, min, max);
	}

	return b;
}

void menu(){
	int opt = 0;
	int mat = 0;
	char nome[30];
	float media, min, max;

	noABB *a = abb_cria();

	do {
		puts("\nQual seria a acao desejada?");
		printf("\t1 - Novo aluno\n\t2 - Imprimir todos alunos\n\t3 - Libera arvore\n\t4 - Maior media\n\t5 - Numero de Aprovados\n\t6 - Imprimir Aprovados\n\t7 - Imprime em Intervalo\n\t8 - Sair\n");
		printf("Opcao: ");
		scanf("%d",&opt);

		switch (opt) {
			case 1:
				setbuf(stdin, NULL);
				printf("--Nome do(a) Aluno(a): ");
				fgets(nome, 30, stdin);

				printf("--Matricula: ");
				scanf("%i",&mat);

				printf("--Media: ");
				scanf("%f",&media);
				a = abb_insere(a, mat, nome, media);
			break;
			case 2:
				puts("\n----Alunos:");
				abb_imprime(a);
			break;
			case 3:
				abb_libera(a);
				a = abb_cria();
				puts("Liberado.");
			break;
			case 4:
				abb_alunoComMaiorMedia(a);
			break;
			case 5:
				printf("\n----Numero de Aprovados: %i",abb_contaAprovados(a));
				puts("");
			break;
			case 6:
				puts("\n----Aprovados:");
				abb_imprimeAprovados(a);
			break;
			case 7:
				printf("\n--Minimo: ");
				scanf("%f",&min);
				printf("--Maximo: ");
				scanf("%f",&max);
				printf("\n----Numero de medias neste intervalo: %i",abb_contaIntervalo(a,min,max));
				puts("");
			break;
		}
	
	}while (opt != 8);

	if (a != NULL) {
		abb_libera(a);
		puts("Fechando.");
	}
}
