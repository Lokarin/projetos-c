// Interface Publica

typedef struct matrizes Matrizes;

Matrizes *criarMatriz(int n);
void preencherMatrizM1(Matrizes *a, int n);
void preencherMatrizM2(Matrizes *a, int n);
void somaMatrizes(Matrizes *a, int n);
void freeMatrizes(Matrizes *a, int n);
