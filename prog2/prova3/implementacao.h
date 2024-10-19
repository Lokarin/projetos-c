// Publico

typedef struct aluno Aluno;
typedef struct noABB noABB;

noABB *abb_cria();
noABB *abb_insere(noABB *a, int mat, char *nome, float media);
void abb_imprime(noABB *a);
void abb_libera(noABB *a);
void abb_alunoComMaiorMedia(noABB *a);
int abb_contaAprovados(noABB *a);
void abb_imprimeAprovados(noABB *a);
int abb_contaIntervalo(noABB *a, float min, float max);

void menu();
