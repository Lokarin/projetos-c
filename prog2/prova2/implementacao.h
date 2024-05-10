// Publico

typedef struct data Data;
typedef struct contato Contato;
typedef struct no No;
typedef struct lista Lista;
void cria_agenda(Lista *lista);
void insere_contato(Lista *lista);
void lista_contatos(Lista lista);
No* busca_contatos(Lista *lista);
No* remove_contato(Lista *lista);
void atualiza_contato(Lista *lista);
void libera_agenda(Lista *lista);
void menu();
