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
    Carta carta1 = {"RJ", "A01", "Piraí", 300000, 1200.5, 15000000000.0, 15};
    Carta carta2 = {"RJ", "A02", "Volta Redonda", 200000, 800.3, 10000000000.0, 10};

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    char atributoEscolhido[] = "População";

    
    float valor1 = carta1.populacao;
    float valor2 = carta2.populacao;

    
    printf("Comparação de cartas (Atributo: %s)\n\n", atributoEscolhido);

    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);


    if (strcmp(atributoEscolhido, "Densidade Populacional") == 0) {
        if (valor1 < valor2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 < valor1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {
        if (valor1 > valor2) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        } else if (valor2 > valor1) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }

    return 0;
}
