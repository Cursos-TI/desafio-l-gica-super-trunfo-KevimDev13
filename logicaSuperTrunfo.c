#include <stdio.h>

int main() {
    // ... (Toda a parte de leitura e cálculo das cartas permanece a mesma) ...
    // Carta 1
    unsigned long int populacao1;
    int ponto1;
    float area1, pib1;
    float densidade1, pib_per_capita1, super_poder1;
    char estado1[50], codigo1[50], cidade1[50];

    printf("===== Carta 1 =====\n");
    printf("Qual o estado (A-H)?: ");
    scanf("%s", estado1);
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    printf("Nome da cidade: ");
    scanf("%s", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área em km²: ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &ponto1);

    // Cálculo da carta 1
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0) / (float)populacao1;
    super_poder1 = (float)populacao1 + area1 + (pib1 * 1000000000.0) +
                   ponto1 + pib_per_capita1 + (1.0f / densidade1);

    // Carta 2
    unsigned long int populacao2;
    int ponto2;
    float area2, pib2;
    float densidade2, pib_per_capita2, super_poder2;
    char estado2[50], codigo2[50], cidade2[50];

    printf("\n===== Carta 2 =====\n");
    printf("Qual o estado (A-H)?: ");
    scanf("%s", estado2);
    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", codigo2);
    printf("Nome da cidade: ");
    scanf("%s", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área em km²: ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &ponto2);

    // Cálculo da carta 2
    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0) / (float)populacao2;
    super_poder2 = (float)populacao2 + area2 + (pib2 * 1000000000.0) +
                   ponto2 + pib_per_capita2 + (1.0f / densidade2);

    // Exibindo os dados da carta 1 e 2
    // ... (parte de exibição de dados permanece a mesma) ...
    printf("\n===== Dados da Carta 1 =====\n");
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("...\n"); // Omitido para economizar espaço
    printf("\n===== Dados da Carta 2 =====\n");
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("...\n"); // Omitido para economizar espaço


    // ==================================================================
    //      INÍCIO DA LÓGICA COM IF-ELSE ANINHADO (SEM ELSE IF)
    // ==================================================================
    printf("\n===== Comparação de Cartas =====\n");

    // Comparação de População
    printf("População: ");
    if (populacao1 > populacao2) {
        printf("Carta 1 venceu!\n");
    } else {
        // Se a populacao1 NÃO é maior, então ou ela é menor ou é igual.
        // Agora verificamos essas duas possibilidades.
        if (populacao2 > populacao1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }

    // Comparação de Área
    printf("Área: ");
    if (area1 > area2) {
        printf("Carta 1 venceu!\n");
    } else {
        if (area2 > area1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }

    // Comparação de PIB
    printf("PIB: ");
    if (pib1 > pib2) {
        printf("Carta 1 venceu!\n");
    } else {
        if (pib2 > pib1) {
            printf("Carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }

    // E assim por diante para todos os outros atributos...
    // (O código completo teria a mesma lógica para Pontos Turísticos, Densidade, etc.)

    return 0;
}