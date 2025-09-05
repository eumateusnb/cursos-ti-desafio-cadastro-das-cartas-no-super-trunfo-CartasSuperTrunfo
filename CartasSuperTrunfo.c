#include <stdio.h>

int main() {
    
    printf("Carta 1:\n");
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
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos turísticos: %d\n", pontos_turisticos);

    printf("\nCarta 2:\n");
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
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontos_turisticos2);

    // Cálculos
    float densidade1 = populacao / area;
    float pib_per_capita1 = (pib * 1000000000.0) / populacao;

    float densidade2 = populacao2 / area2;
    float pib_per_capita2 = (pib2 * 1000000000.0) / populacao2;

    float super_poder1 = populacao + area + pib + pontos_turisticos + pib_per_capita1 + (1.0 / densidade1);
    float super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1.0 / densidade2);

    printf("\nCarta 1:\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\nCarta 2:\n");
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparações
    printf("\n--- Comparação de Cartas ---\n");
    printf("População: Carta 1 venceu (%d)\n", populacao > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontos_turisticos > pontos_turisticos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2); // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder1 > super_poder2);

    return 0;
}