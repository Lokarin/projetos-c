#include <stdio.h>

int quantidade, escolha = 0;

int cozinha(int escolha, int quantidade) {
	float preco = 0;
	switch (escolha) {
		case 100:
			preco = 1.20 * quantidade;
			printf("Pedido:\n\
	%i Cachorro(s) Quente(s)\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;

		case 101:
			preco = 1.30 * quantidade;
			printf("Pedido:\n\
	%i Bauru(s) Simples\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;

		case 102:
			preco = 1.50 * quantidade;
			printf("Pedido:\n\
	%i Bauru(s) com Ovo\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;

		case 103:
			preco = 1.20 * quantidade;
			printf("Pedido:\n\
	%i Hamburger(es)\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;

		case 104:
			preco = 1.70 * quantidade;
			printf("Pedido:\n\
	%i Cheeseburger(es)\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;

		case 105:
			preco = 2.20 * quantidade;
			printf("Pedido:\n\
	%i Suco(s)\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;

		case 106:
			preco = 1.00 * quantidade;
			printf("Pedido:\n\
	%i Refrigerante(s)\n\
Preco total: R$%.2f\n",quantidade,preco);
		break;
	}

	return 0;
}

int main() {
	printf("Escolha um dos itens\n\
	100 - Cachorro Quente\n\
	101 - Bauru Simples\n\
	102 - Bauru com ovo\n\
	103 - Hamburger\n\
	104 - Cheeseburger\n\
	105 - Suco\n\
	106 - Refrigenrante\n\
Numero do item desejado: ");
	scanf("%i",&escolha);
	printf("Quantos?: ");
	scanf("%i",&quantidade);

	cozinha(escolha,quantidade);

	return 0;
}
