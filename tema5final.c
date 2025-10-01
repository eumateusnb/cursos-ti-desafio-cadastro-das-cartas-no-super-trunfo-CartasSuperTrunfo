#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 7
#define AGUA 0
#define NAVIO 3
#define HABILIDADE_AFETADA 5


bool validar_posicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho);
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho);
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);

void criar_cone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criar_cruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void criar_octaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);
void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int centro_l, int centro_c);

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    int navios[4][3] = {
        {1, 1, 0},
        {5, 8, 1},
        {7, 0, 2},
        {0, 9, 3}
    };
    
    int navios_posicionados = 0;
    printf("Iniciando o posicionamento dos navios (Tamanho fixo = %d)...\n", TAMANHO_NAVIO);
    
    for (int k = 0; k < 4; k++) {
        int linha = navios[k][0];
        int coluna = navios[k][1];
        int direcao = navios[k][2];
        
        if (validar_posicao(tabuleiro, linha, coluna, direcao, TAMANHO_NAVIO)) {
            posicionar_navio(tabuleiro, linha, coluna, direcao, TAMANHO_NAVIO);
            navios_posicionados++;
            printf("Navio %d posicionado com sucesso em (%d, %d), direção %d.\n", k + 1, linha, coluna, direcao);
        } else {
            printf("ERRO: O Navio %d não pôde ser posicionado em (%d, %d), direção %d (Limites ou Sobreposição).\n", k + 1, linha, coluna, direcao);
        }
    }
    printf("\nTotal de navios posicionados: %d/4\n", navios_posicionados);
    
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    criar_cone(cone);
    int centro_cone_l = 0;
    int centro_cone_c = 4;
    printf("\nAplicando Habilidade CONE (Tamanho %dx%d) no centro especificado (%d, %d)...\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE, centro_cone_l, centro_cone_c);
    aplicar_habilidade(tabuleiro, cone, centro_cone_l, centro_cone_c);

    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    criar_cruz(cruz);
    int centro_cruz_l = 5;
    int centro_cruz_c = 2;
    printf("Aplicando Habilidade CRUZ (Tamanho %dx%d) no centro especificado (%d, %d)...\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE, centro_cruz_l, centro_cruz_c);
    aplicar_habilidade(tabuleiro, cruz, centro_cruz_l, centro_cruz_c);

    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    criar_octaedro(octaedro);
    int centro_octaedro_l = 8;
    int centro_octaedro_c = 6;
    printf("Aplicando Habilidade OCTAEDRO (Tamanho %dx%d) no centro especificado (%d, %d)...\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE, centro_octaedro_l, centro_octaedro_c);
    aplicar_habilidade(tabuleiro, octaedro, centro_octaedro_l, centro_octaedro_c);
    
    printf("\n--- Tabuleiro Final com Navios e Habilidades ---\n");
    exibir_tabuleiro(tabuleiro);
    printf("Legenda: %d = Água, %d = Navio, %d = Área de Habilidade\n", AGUA, NAVIO, HABILIDADE_AFETADA);
    
    return 0;
}

void criar_cone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro_hab = TAMANHO_HABILIDADE / 2; // 3 para 7x7
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= centro_hab - i && j <= centro_hab + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criar_cruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro_hab = TAMANHO_HABILIDADE / 2; // 3 para 7x7
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro_hab || j == centro_hab) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void criar_octaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro_hab = TAMANHO_HABILIDADE / 2;
    int raio = centro_hab;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int distancia_manhattan = abs(i - centro_hab) + abs(j - centro_hab);
            if (distancia_manhattan <= raio) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

void aplicar_habilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int centro_l, int centro_c) {
    int offset = TAMANHO_HABILIDADE / 2;
    for (int l_hab = 0; l_hab < TAMANHO_HABILIDADE; l_hab++) {
        for (int c_hab = 0; c_hab < TAMANHO_HABILIDADE; c_hab++) {
            int l_tab = centro_l + (l_hab - offset);
            int c_tab = centro_c + (c_hab - offset);
            if (habilidade[l_hab][c_hab] == 1) {
                if (l_tab >= 0 && l_tab < TAMANHO_TABULEIRO && 
                    c_tab >= 0 && c_tab < TAMANHO_TABULEIRO) {
                    tabuleiro[l_tab][c_tab] = HABILIDADE_AFETADA;
                }
            }
        }
    }
}

bool validar_posicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha_inicial;
        int c = coluna_inicial;
        switch (direcao) {
            case 0:
                c += i;
                break;
            case 1:
                l += i;
                break;
            case 2:
                l += i;
                c += i;
                break;
            case 3:
                l += i;
                c -= i;
                break;
            default:
                return false; 
        }
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
            return false;
        }
        if (tabuleiro[l][c] != AGUA) {
            return false;
        }
    }
    return true;
}

void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha_inicial, int coluna_inicial, int direcao, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int l = linha_inicial;
        int c = coluna_inicial;
        switch (direcao) {
            case 0:
                c += i;
                break;
            case 1:
                l += i;
                break;
            case 2:
                l += i;
                c += i;
                break;
            case 3:
                l += i;
                c -= i;
                break;
        }
        tabuleiro[l][c] = NAVIO;
    }
}

void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%3d", j);
    }
    printf("\n");

    int largura = 3 * TAMANHO_TABULEIRO + 3;
    printf("  +");
    for (int i = 0; i < largura; i++) putchar('-');
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%3d", tabuleiro[i][j]); 
        }
        printf("\n");
    }
}