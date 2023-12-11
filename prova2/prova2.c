#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
	char nome[30];
	char genero[20];
	float duracao;
	int posicao;
} Musica;

Musica playlist[5];

void preenchePlaylist(Musica *x) {
	for (int i = 0; i < 5; i++) {
		printf("\n---// Dados da musica %i //---\n",i+1);
		printf("Nome da musica %i: ",i+1);
		setbuf(stdin, NULL);
		fgets(x[i].nome, 30, stdin);
		setbuf(stdin, NULL);

		printf("Genero da musica %i: ",i+1);
		fgets(x[i].genero, 20, stdin);

		printf("Duracao da musica %i (em minutos): ",i+1);
		scanf("%f",&x[i].duracao);
		setbuf(stdin, NULL);

		x[i].posicao = i;
	}
}

int playlistEstaVazia(const Musica *x, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (x[i].posicao != 0) {
            return 0;
        }
    }
    return 1;
}

void lerPlaylist(Musica *x) {
	if (playlistEstaVazia(playlist, 5)) {
		puts("--> Esta playlist esta vazia");

	} else {
		for (int i = 0; i < 5; i++) {
			printf("\n---// Dados da musica %i //---\n",i+1);
			printf("Nome da musica %i: %s",i+1,x[i].nome);

			printf("Genero da musica %i: %s",i+1,x[i].genero);

			printf("Duracao da musica %i (em minutos): %.2f\n",i+1,x[i].duracao);

			printf("Posicao da musica %i na playlist: %i\n",i+1,x[i].posicao+1);
		}
	}
}

void procura(Musica *x) {
	if (playlistEstaVazia(playlist, 5)) {
		puts("--> Esta playlist esta vazia");

	} else {
		puts("\n---// Modo de Pesquisa //---");

		int type, encontrado = 0;

		printf("Voce gostaria de pesquisar por Nome ou por Genero?\n\
		0 - Nome\n\
		1 - Genero\n\
R: ");
		scanf("%i",&type);

		char search[20];
		printf((type == 0) ? "Qual seria o nome da musica?: " : "Por qual genero deve ser realizado a busca?: ");
		getchar();
		fgets(search, 20, stdin);

		//printf("%s",search);

		if (type == 0) {
			for (int i = 0; i < 5; i++) {
				int resultado = strcmp(search, x[i].nome);

				if (resultado == 0) {
					printf("A musica %i esta presente nesta playlist\n",i+1);
					encontrado = 1;
				}
			
			}

		} else if (type == 1) {
			for (int i = 0; i < 5; i++) {
				int resultado = strcmp(search, x[i].genero);
				//printf("resultado: %i; genero de x: %s",resultado,x[i].genero);

				if (resultado == 0) {
					printf("\n---// Dados da musica %i //---\n",i+1);
					printf("Nome da musica %i: %s",i+1,x[i].nome);

					printf("Genero da musica %i: %s",i+1,x[i].genero);

					printf("Duracao da musica (em minutos) %i: %.2f\n",i+1,x[i].duracao);

					printf("Posicao da musica %i na playlist: %i\n",i+1,x[i].posicao+1);

					encontrado = 1;
				}
			}

		} else {
			puts("Operacao nao existe");
			exit(1);
		}

		if (encontrado == 0) {
			puts((type == 0) ? "Nenhuma musica nesta playlist tem este nome." : "Nenhuma musica nesta playlist que seja deste genero.");
		}
	}
}

int main() {
	int escolha = 4;

	while (1) {
		puts("\n---// Menu Inicial //---");
		printf("Operacoes: \n\
	0 - Preencher playlist\n\
	1 - Verificar playlist\n\
	2 - Buscar na playlist\n\
	3 - Fechar o progama\n\
R: ");
		scanf("%i",&escolha);

		if (escolha == 0) {
			preenchePlaylist(playlist);

		} else if (escolha == 1) {
			lerPlaylist(playlist);

		} else if (escolha == 2) {
			procura(playlist);
		
		} else if (escolha == 3) {
			puts("Fechando o progama...");
			exit(1);
		}
	}

	return 0;
}
