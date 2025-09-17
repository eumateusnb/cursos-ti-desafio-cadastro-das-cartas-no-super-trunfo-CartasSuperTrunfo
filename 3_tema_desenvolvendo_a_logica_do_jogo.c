#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[20];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

void mostrarMenu(int excluir) {
    printf("\nEscolha um atributo para comparar:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Populacional\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
    printf("Opção: ");
}

float obterValor(Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.numPontosTuristicos;
        case 5: return c.densidadePopulacional;
        case 6: return c.pibPerCapita;
        default: return -1; // erro
    }
}

const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "Desconhecido";
    }
}

int main() {
    Carta carta1 = {"RJ", "A01", "Piraí", 300000, 1200.5, 15000000000.0, 15};
    Carta carta2 = {"RJ", "A02", "Volta Redonda", 200000, 800.3, 10000000000.0, 10};

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int escolha1, escolha2;
    
    mostrarMenu(0);
    scanf("%d", &escolha1);

    mostrarMenu(escolha1);
    scanf("%d", &escolha2);

    float valor1_attr1 = obterValor(carta1, escolha1);
    float valor2_attr1 = obterValor(carta2, escolha1);

    float valor1_attr2 = obterValor(carta1, escolha2);
    float valor2_attr2 = obterValor(carta2, escolha2);

    int pontosCarta1 = 0, pontosCarta2 = 0;

    if (escolha1 == 5) {
        if (valor1_attr1 < valor2_attr1) pontosCarta1++;
        else if (valor2_attr1 < valor1_attr1) pontosCarta2++;
    } else {
        if (valor1_attr1 > valor2_attr1) pontosCarta1++;
        else if (valor2_attr1 > valor1_attr1) pontosCarta2++;
    }

    if (escolha2 == 5) {
        if (valor1_attr2 < valor2_attr2) pontosCarta1++;
        else if (valor2_attr2 < valor1_attr2) pontosCarta2++;
    } else {
        if (valor1_attr2 > valor2_attr2) pontosCarta1++;
        else if (valor2_attr2 > valor1_attr2) pontosCarta2++;
    }

    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\n--- RESULTADO DA RODADA ---\n");
    printf("Carta 1: %s (%s)\n", carta1.nomeCidade, carta1.estado);
    printf(" - %s: %.2f\n", nomeAtributo(escolha1), valor1_attr1);
    printf(" - %s: %.2f\n", nomeAtributo(escolha2), valor1_attr2);
    printf("Soma: %.2f\n\n", soma1);

    printf("Carta 2: %s (%s)\n", carta2.nomeCidade, carta2.estado);
    printf(" - %s: %.2f\n", nomeAtributo(escolha1), valor2_attr1);
    printf(" - %s: %.2f\n", nomeAtributo(escolha2), valor2_attr2);
    printf("Soma: %.2f\n\n", soma2);

    if (soma1 > soma2) {
        printf("Vencedor: Carta 1 (%s)\n", carta1.nomeCidade);
    } else if (soma2 > soma1) {
        printf("Vencedor: Carta 2 (%s)\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
