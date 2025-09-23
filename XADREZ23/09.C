#include <stdio.h>


void moverTorre(int atual, int limite) {
    if (atual > limite) return;
    printf("Direita - Casa %d\n", atual);
    moverTorre(atual + 1, limite);
}

void moverRainha(int atual, int limite) {
    if (atual > limite) return;
    printf("Esquerda - Casa %d\n", atual);
    moverRainha(atual + 1, limite);
}

void moverBispo(int linhaAtual, int linhasTotais) {
    if (linhaAtual > linhasTotais) return;

    for (int coluna = 1; coluna <= linhaAtual; coluna++) {
        printf("Cima, Direita - Linha %d, Passo %d\n", linhaAtual, coluna);
    }

    moverBispo(linhaAtual + 1, linhasTotais);
}

int main() {

    int casasTorre   = 5;
    int casasBispo   = 4;
    int casasRainha  = 8;
    int casasCavaloY = 2;
    int casasCavaloX = 1;

    printf("Movimento da Torre (Recursão):\n");
    moverTorre(1, casasTorre);

    printf("\nMovimento do Bispo (Recursão + Loops Aninhados):\n");
    moverBispo(1, casasBispo);

    printf("\nMovimento da Rainha (Recursão):\n");
    moverRainha(1, casasRainha);

    printf("\nMovimento do Cavalo (Loops Aninhados):\n");

    for (int i = 1; i <= casasCavaloY; i++) {

        for (int j = 1; j <= casasCavaloX; j++) {

            if (i == 2 && j == 1) {

                printf("Direita - Casa Final (%d,%d)\n", i, j);
                break;
            }

            printf("Cima - Casa Vertical %d\n", i);


            if (i % 2 != 0) continue;

            printf("Direita - Passo Horizontal %d\n", j);
        }
    }

    return 0;
}
