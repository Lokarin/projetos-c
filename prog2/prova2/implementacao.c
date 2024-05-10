# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "implementacao.h"

struct data{
	int dia;
	int mes;
};

struct contato{
	char nome[50];
	char telefone[15];
	char celular[15];
	char email[50];
	Data aniversario;
};

struct no{
    Contato info;
    struct no *proximo;
};

struct lista{
    No *inicio;
    int tam;
};

void cria_agenda(Lista *lista){
    lista->inicio = NULL;
    lista->tam = 0;
}

// procedimento para inserir novo contato
void insere_contato(Lista *lista){
    No *aux, *aux2, *novo = malloc(sizeof(No));

    if(novo){
	setbuf(stdin, NULL);
	printf("Insira o nome do contato: ");
	fgets(novo->info.nome, 50, stdin);

	if (lista->inicio == NULL) {
		novo->proximo = NULL;	
		lista->inicio = novo;

		printf("Insira o telefone do contato: ");
		fgets(novo->info.telefone, 15, stdin);

		printf("Insira o celular do contato: ");
		fgets(novo->info.celular, 15, stdin);

		printf("Insira o email do contato: ");
		fgets(novo->info.email, 50, stdin);

		printf("Insira o dia do aniversario: ");
		scanf("%i",&novo->info.aniversario.dia);

		printf("Insira o mes do aniversario: ");
		scanf("%i",&novo->info.aniversario.mes);

		lista->tam++;
	} else {
		aux = lista->inicio;
		while (aux->proximo && ((strcmp(novo->info.nome, aux->proximo->info.nome)) > 0)) {
			aux2 = aux;
			aux = aux->proximo;		
		}
		if ((strcmp(novo->info.nome, aux->info.nome)) == 0) {
			printf("Já existe um contato com este nome! Cancelando processo.");
		} else {
			if ((strcmp(novo->info.nome, aux->info.nome)) > 0) {
				if (aux->proximo) {
					novo->proximo = aux->proximo;
				} else {
					novo->proximo = NULL;
				}
				aux->proximo = novo;
				
			} else {
				novo->proximo = aux;
				lista->inicio = novo;			
			}

			printf("Insira o telefone do contato: ");
			fgets(novo->info.telefone, 15, stdin);

			printf("Insira o celular do contato: ");
			fgets(novo->info.celular, 15, stdin);

			printf("Insira o email do contato: ");
			fgets(novo->info.email, 50, stdin);

			printf("Insira o dia do aniversario: ");
			scanf("%i",&novo->info.aniversario.dia);

			printf("Insira o mes do aniversario: ");
			scanf("%i",&novo->info.aniversario.mes);

			lista->tam++;
		}
	}
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void lista_contatos(Lista lista){
    No *no = lista.inicio;

    if (lista.inicio) {
	    printf("\n\n\tExistem %i contatos: ", lista.tam);
	    for (int i = 1; no; i++) {
		    printf("\n\n\t---| Contato %i |---\n",i);
		    printf("Nome: %s",no->info.nome);
		    printf("Telefone: %s",no->info.telefone);
		    printf("Celular: %s",no->info.celular);
		    printf("Email: %s",no->info.email);
		    printf("Aniversario: %i/%i",no->info.aniversario.dia,no->info.aniversario.mes);

		    no = no->proximo;
	    }
    } else {
	    printf("\n\nNao ha contatos nesta agenda.");
    }
    printf("\n\n");
}

No* busca_contatos(Lista *lista){
	int i;
	char pesquisa[50];
	No *aux = lista->inicio;

	setbuf(stdin, NULL);
	printf("Nome do contato procurado: ");
	fgets(pesquisa, 50, stdin);

	for (i = 1; (aux->proximo && ((strcmp(pesquisa, aux->info.nome)) != 0)) && aux ; i++) {
		aux = aux->proximo;	
	}
	if ((strcmp(pesquisa, aux->info.nome)) == 0) {
		printf("\nInformacoes do contato\n");
		printf("Nome: %s",aux->info.nome);
		printf("Telefone: %s",aux->info.telefone);
		printf("Celular: %s",aux->info.celular);
		printf("Email: %s",aux->info.email);
		printf("Aniversario: %i/%i\n",aux->info.aniversario.dia,aux->info.aniversario.mes);
		return (void*)aux;
	} else {
		puts("\nNenhum contato com este nome.");
		return NULL;
	}
}

No* remove_contato(Lista *lista) {
	No *aux = NULL;
	No *remover = busca_contatos(lista);
	if (remover) {
		aux = lista->inicio;
		while (aux->proximo && (aux->proximo != remover) && (aux != remover)) {
			aux = aux->proximo;
		}

		if (aux == remover) {
			//printf("O proximo: %s",aux->proximo->info.nome);
			lista->inicio = aux->proximo;
		} else {
			aux->proximo = remover->proximo;
		}

		lista->tam--;

		return remover;
	} else {
		return NULL;
	}
}

void atualiza_contato(Lista *lista) {
	No *atualizar = busca_contatos(lista);

	if (atualizar) {
		puts("\n\tEditando contato");

		printf("Insira o telefone do contato: ");
		fgets(atualizar->info.telefone, 15, stdin);

		printf("Insira o celular do contato: ");
		fgets(atualizar->info.celular, 15, stdin);

		printf("Insira o email do contato: ");
		fgets(atualizar->info.email, 50, stdin);

		printf("Insira o dia do aniversario: ");
		scanf("%i",&atualizar->info.aniversario.dia);

		printf("Insira o mes do aniversario: ");
		scanf("%i",&atualizar->info.aniversario.mes);
	}
}

void libera_agenda(Lista *lista) {
	No *aux = NULL;
	No *aux2 = NULL;

	if (lista) {
		aux = lista->inicio;
		while (aux->proximo) {
			aux2 = aux;
			printf("Removendo %s",aux2->info.nome);
			aux = aux->proximo;
			free(aux2);
			aux2 = NULL;
			lista->tam--;
		}
		if (aux) {
			printf("Removendo %s",aux->info.nome);
			free(aux);
			aux = NULL;
			lista->tam--;
			lista->inicio = NULL;
		}
	}
}

void menu() {

    int opcao, valor, anterior;
    Lista lista;
    No *removido;

    cria_agenda(&lista);

    do{
	puts("\nQual seria a acao desejada?");
        printf("\t1 - Novo Contato\n\t2 - Listar Agenda\n\t3 - Buscar Contato\n\t4 - Editar Contato\n\t5 - Remover\n\t6 - Sair\n");
	printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
	            insere_contato(&lista);
            break;
        case 2:
		    lista_contatos(lista);
            break;
        case 3:
		    busca_contatos(&lista);
            break;
        case 4:
	            atualiza_contato(&lista);	
            break;
        case 5:
            removido = remove_contato(&lista);
            if(removido){
		puts("\nContato removido.");
                free(removido);
            }
            else {
		puts("");
	    }
            break;
	case 9:
	    libera_agenda(&lista);
	    break;
        default:
            if(opcao != 6)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 6);

    if (lista.inicio != NULL) {
	    libera_agenda(&lista);
	    puts("Fechando.");
    }
}
