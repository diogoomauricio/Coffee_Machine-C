#include <stdio.h>

void limpa_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int escolha;
    double dinheiro, preco, troco;

    printf("[Coffee Machine]\n");
    printf("1 -- [Expresso]\n");
    printf("2 -- [Normal Coffee]\n");
    printf("3 -- [Americano]\n");
    printf("4 -- [Chocolate]\n");

    // Lê a escolha (1-4), repetindo se for inválida
    while (1) {
        printf("Escolha a bebida (1-4): ");
        if (scanf("%d", &escolha) == 1 && escolha >= 1 && escolha <= 4) break;
        printf("Entrada inválida. Digite um número de 1 a 4.\n");
        limpa_buffer();
    }

    switch (escolha) {
        case 1: preco = 1.50; break;
        case 2: preco = 2.00; break;
        case 3: preco = 2.50; break;
        case 4: preco = 3.00; break;
    }

    printf("Preço: %.2lf€\n", preco);

    // Lê o dinheiro, repetindo se não for número
    while (1) {
        printf("Insira o dinheiro: ");
        if (scanf("%lf", &dinheiro) == 1 && dinheiro >= 0) break;
        printf("Entrada inválida. Insira um valor numérico (ex.: 1.50).\n");
        limpa_buffer();
    }

    if (dinheiro < preco) {
        printf("Faltam %.2lf€ para o seu café.\n", preco - dinheiro);
    } else {
        troco = dinheiro - preco;
        printf("Troco: %.2lf€\n", troco);
    }

    return 0;
}

