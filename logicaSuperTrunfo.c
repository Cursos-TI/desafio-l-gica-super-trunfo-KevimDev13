#include <stdio.h>

int main() {
    // ==================================================================
    // CADASTRO DAS CARTAS
    // ==================================================================
    unsigned long int populacao1, populacao2;
    int ponto1, ponto2;
    float area1, area2, pib1, pib2;
    float densidade1, densidade2;
    char estado1[50], codigo1[50], cidade1[50];
    char estado2[50], codigo2[50], cidade2[50];

    // ---------------- Carta 1 ----------------
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

    // Calcula densidade demográfica (população dividida pela área)
    densidade1 = populacao1 / area1;

    // ---------------- Carta 2 ----------------
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

    // Calcula densidade demográfica da carta 2
    densidade2 = populacao2 / area2;

    // ==================================================================
    // ESCOLHA DOS ATRIBUTOS
    // ==================================================================
    int atributo1, atributo2; // guarda os números dos atributos escolhidos
    float valor1_carta1, valor1_carta2; // valores do primeiro atributo
    float valor2_carta1, valor2_carta2; // valores do segundo atributo
    float soma1 = 0, soma2 = 0; // soma final de cada carta

    // Exibe o menu inicial
    printf("\n===== BATALHA SUPER TRUNFO =====\n");
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1. População (Maior vence)\n");
    printf("2. Área (Maior vence)\n");
    printf("3. PIB (Maior vence)\n");
    printf("4. Pontos Turísticos (Maior vence)\n");
    printf("5. Densidade Demográfica (MENOR vence!)\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &atributo1);

    // Exibe o menu novamente, mas sem repetir o atributo anterior
    printf("\nAgora escolha o SEGUNDO atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i == atributo1) continue; // pula o atributo já escolhido
        switch (i) {
            case 1: printf("1. População (Maior vence)\n"); break;
            case 2: printf("2. Área (Maior vence)\n"); break;
            case 3: printf("3. PIB (Maior vence)\n"); break;
            case 4: printf("4. Pontos Turísticos (Maior vence)\n"); break;
            case 5: printf("5. Densidade Demográfica (MENOR vence!)\n"); break;
        }
    }
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &atributo2);

    // Impede que o usuário escolha o mesmo atributo duas vezes
    if (atributo2 == atributo1) {
        printf("\nErro: você escolheu o mesmo atributo duas vezes!\n");
        return 0;
    }

    // ==================================================================
    // COMPARAÇÃO DOS ATRIBUTOS
    // ==================================================================
    switch (atributo1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = ponto1; valor1_carta2 = ponto2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        default: printf("Atributo inválido!\n"); return 0;
    }
    switch (atributo2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = ponto1; valor2_carta2 = ponto2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        default: printf("Atributo inválido!\n"); return 0;
    }

    // ==================================================================
    // CÁLCULO DAS SOMAS
    // ==================================================================
    // Se o atributo for densidade (5), invertemos o valor (1 / densidade)
    // pois menor densidade significa vantagem.
    // Isso evita números enormes e mantém a escala justa.
    soma1 += (atributo1 == 5) ? (1 / valor1_carta1) : valor1_carta1;
    soma2 += (atributo1 == 5) ? (1 / valor1_carta2) : valor1_carta2;
    soma1 += (atributo2 == 5) ? (1 / valor2_carta1) : valor2_carta1;
    soma2 += (atributo2 == 5) ? (1 / valor2_carta2) : valor2_carta2;

    // ==================================================================
    // EXIBIÇÃO DOS RESULTADOS
    // ==================================================================
    printf("\n===== RESULTADOS =====\n");
    printf("Carta 1: %s\nCarta 2: %s\n\n", cidade1, cidade2);

    // Exibe o nome e valores do primeiro atributo
    printf("Atributo 1: ");
    switch (atributo1) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", cidade1, valor1_carta1, cidade2, valor1_carta2);

    // Exibe o nome e valores do segundo atributo
    printf("Atributo 2: ");
    switch (atributo2) {
        case 1: printf("População\n"); break;
        case 2: printf("Área\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Pontos Turísticos\n"); break;
        case 5: printf("Densidade Demográfica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n\n", cidade1, valor2_carta1, cidade2, valor2_carta2);

    // Mostra o total de pontos somados de cada carta
    printf("Soma ponderada dos atributos:\n");
    printf("%s: %.2f\n", cidade1, soma1);
    printf("%s: %.2f\n", cidade2, soma2);

    // ==================================================================
    // DECISÃO FINAL USANDO OPERADOR TERNÁRIO
    // ==================================================================
    // Usa o operador ternário para comparar as somas e mostrar o vencedor
    (soma1 > soma2) ? printf("\nVencedor: %s 🏆\n", cidade1) :
    (soma2 > soma1) ? printf("\nVencedor: %s 🏆\n", cidade2) :
                      printf("\nResultado: Empate!\n");

    return 0;
}