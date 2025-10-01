#include <stdio.h>
#include <stdbool.h>

bool validar_posicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho);
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho);
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int navios[4][3] = {
        // Navios Horizontais/Verticais (Normais)
        {1, 1, 0}, // Navio 1: Horizontal, começa em (1, 1)
        {5, 8, 1}, // Navio 2: Vertical, começa em (5, 8)
        
        {7, 0, 2}, // Navio 3: Diagonal Principal (i+, j+), começa em (7, 0)
        {0, 9, 3}  // Navio 4: Diagonal Secundária (i+, j-), começa em (0, 9)
    };
    
    int navios_posicionados = 0;

    printf("Iniciando o posicionamento dos navios (Tamanho fixo = %d)...\n", TAMANHO_NAVIO);
    
    for (int k = 0; k < 4; k++) {
        int linha = navios[k][0];
        int coluna = navios[k][1];
        int direcao = navios[k][2];
        
        if (validar_posicao(tabuleiro, linha, coluna, direcao, TAMANHO_NAVIO)) {
            // 3. Posicionamento do Navio
            posicionar_navio(tabuleiro, linha, coluna, direcao, TAMANHO_NAVIO);
            navios_posicionados++;
            printf("Navio %d posicionado com sucesso em (%d, %d), direção %d.\n", k + 1, linha, coluna, direcao);
        } else {
            printf("ERRO: O Navio %d não pôde ser posicionado em (%d, %d), direção %d (Limites ou Sobreposição).\n", k + 1, linha, coluna, direcao);
        }
    }

    printf("\nTotal de navios posicionados: %d/4\n", navios_posicionados);
    
    printf("\n--- Tabuleiro Final do Batalha Naval ---\n");
    (tabuleiro);
    printf("Legenda: %d = Água, %d = Navio\n", AGUA, NAVIO);
    
}
    (int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha_inicial;
        int c = coluna_inicial;

        switch (direcao) {
            case 0: // Horizontal (coluna++)
                c += i;
                break;
            case 1: // Vertical (linha++)
                l += i;
                break;
            case 2: // Diagonal Principal (linha++, coluna++)
                l += i;
                c += i;
                break;
            case 3: // Diagonal Secundária (linha++, coluna--)
                l += i;
                c -= i;
                break;
            default:
        }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
        }

        if (tabuleiro[l][c] != AGUA) {
        }
    }
}

void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        int l = linha_inicial;
        int c = coluna_inicial;

        switch (direcao) {
            case 0: // Horizontal
                c += i;
                break;
            case 1: // Vertical
                l += i;
                break;
            case 2: // Diagonal Principal (i+, j+)
                l += i;
                c += i;
                break;
            case 3: // Diagonal Secundária (i+, j-)
                l += i;
                c -= i;
                break;
        }
    
        tabuleiro[l][c] = NAVIO;
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   "); // Espaço para alinhar com o índice da linha
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%3d", j); // 3 espaços para cada índice de coluna
    }
    printf("\n");
    
    printf("  +-------------------------------\n");


    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); // Imprime o índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%3d", tabuleiro[i][j]); 
        }
        printf("\n"); // Nova linha ao final de cada linha do tabuleiro
    }
return 0;
}

