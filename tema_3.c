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

int main() {
    // Cadastro das cartas (fixas, conforme simplificação do desafio)
    Carta carta1 = {"RJ", "A01", "Piraí", 300000, 1200.5, 15000000000.0, 15};
    Carta carta2 = {"RJ", "A02", "Volta Redonda", 200000, 800.3, 10000000000.0, 10};


    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    int opcao;
    float valor1 = 0, valor2 = 0; 
    char atributoEscolhido[50];

    printf("=== MENU DE ATRIBUTOS ===\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("==========================\n");
    printf("Escolha o atributo para comparar: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            strcpy(atributoEscolhido, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2:
            strcpy(atributoEscolhido, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3:
            strcpy(atributoEscolhido, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4:
            strcpy(atributoEscolhido, "Número de Pontos Turísticos");
            valor1 = carta1.numPontosTuristicos;
            valor2 = carta2.numPontosTuristicos;
            break;
        case 5:
            strcpy(atributoEscolhido, "Densidade Demográfica");
            valor1 = carta1.densidadePopulacional;
            valor2 = carta2.densidadePopulacional;
            break;
        default:
            printf("\nOpção inválida! Encerrando programa.\n");
            return 0;
    }

    printf("=== COMPARAÇÃO DE CARTAS (Atributo: %s) ===\n", atributoEscolhido);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    if (strcmp(atributoEscolhido, "Densidade Demográfica") == 0) {
        // Na densidade, vence o MENOR
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 < valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 > valor1) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }

    return 0;
}