#include <stdio.h>
#include <stdbool.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int linhaN1 = 2;
    int colunaN1 = 4;

    int linhaN2 = 5;
    int colunaN2 = 6;

    bool validoN1 = (colunaN1 + TAM_NAVIO <= TAM);
    bool validoN2 = (linhaN2 + TAM_NAVIO <= TAM);
    bool sobreposicao = false;
    if (validoN1 && validoN2) {
        for (i = 0; i < TAM_NAVIO; i++) {
            for (j = 0; j < TAM_NAVIO; j++) {
                if ((linhaN2 + i) == linhaN1 && (colunaN2) == (colunaN1 + j)) {
                    sobreposicao = true;
                }
            }
        }
    }
    if (validoN1 && validoN2 && !sobreposicao) {
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linhaN1][colunaN1 + j] = NAVIO;
        }
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaN2 + i][colunaN2] = NAVIO;
        }
    } else {
        printf("Erro ao posicionar os navios: coordenadas inválidas ou sobreposição.\n");
        return 1;
    }
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
