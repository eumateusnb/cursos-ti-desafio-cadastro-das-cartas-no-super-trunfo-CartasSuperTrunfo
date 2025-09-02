#include <stdio.h>
int main() {
    printf("Carta1:,\n");
    char estado = 'B';
    char codigo[4] = "A05";
    char cidade[10] = "Pirai";
    int populacao = 26000;
    float area = 1000.00;
    float pib = 200.50;
    int pontos_turisticos = 80;

     printf("Estado: %c\n", estado);
     printf("Código: %s\n", codigo);
     printf("Cidade: %s\n", cidade);
     printf("População: %d\n", populacao);
     printf("Área: %.2f km²\n", area);
     printf("Pib: %.2f bilhões de reias\n", pib);
     printf("Pontos turísticos: %d\n", pontos_turisticos);

    printf("Carta2:\n");
    char estado2 = 'C';
    char codigo2[4] = "A04";
    char cidade2[20] = "Volta Redonda";
    int populacao2 = 56000;
    float area2 = 2000.00;
    float pib2 = 400.50;
    int pontos_turisticos2 = 90;

    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("Pib: %.2f bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);

     float densidade1 = populacao / area;
    float pib_per_capita1 = (pib * 1000000000) / populacao; // PIB convertido para reais

    float densidade2 = populacao2 / area2;
    float pib_per_capita2 = (pib2 * 1000000000) / populacao2;

    printf("\n");
    printf("Densidade Populacional: \n");
    printf("Carta 1:\n\n");
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);

    
    printf("\nCarta 2:\n\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);

    return 0;
}