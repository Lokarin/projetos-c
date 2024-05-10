// Publico

typedef struct no No;
typedef struct carro Carro;
Carro criar_carro();
void printDados(Carro c);
No *empilhar(No *topo);
No *desemplilhar(No **topo);
void imprimirPilha(No *topo);
void menu();
