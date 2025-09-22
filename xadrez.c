#include <stdio.h>

int main() {

    
    int i;
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    printf("Movimento da Torre (FOR):\n");
    for (i = 1; i <= casasTorre; i++) {
        printf("Direita - Casa %d\n", i);
    }

    printf("\nMovimento do Bispo (WHILE):\n");
    i = 1;
    while (i <= casasBispo) {
        printf("Cima, Direita - Casa %d\n", i);
        i++;
    }

    printf("\nMovimento da Rainha (DO-WHILE):\n");
    i = 1;
    do {
        printf("Esquerda - Casa %d\n", i);
        i++;
    } while (i <= casasRainha);

    return 0;
}

