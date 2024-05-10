// Publico

typedef struct no No;
typedef struct carro Carro;
typedef struct pilha Pilha;
Carro criar_carro();
void printDados(Carro c);
void criaPilha(Pilha *p);
void empilhar(Pilha *p);
No *desemplilhar(Pilha *p);
void imprimirPilha(Pilha *p);
void menu();
