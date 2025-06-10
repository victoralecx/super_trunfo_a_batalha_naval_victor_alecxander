
```c
#include <stdio.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} CartaSuperTrunfo;

void calcularDerivados(CartaSuperTrunfo *carta) {
    if (carta->area != 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;
    
    if (carta->populacao != 0)
        carta->pibPerCapita = carta->pib / carta->populacao;
    else
        carta->pibPerCapita = 0;
}

int main() {
    // Cadastro das cartas
    CartaSuperTrunfo carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 700000.0, 10, 0, 0};
    CartaSuperTrunfo carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.50, 400000.0, 8, 0, 0};
    
    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    int opcao;
    printf("Escolha o atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n5 - PIB per capita\n");
    scanf("%d", &opcao);

    float valor1, valor2;
    char atributo[30];

    switch (opcao) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            snprintf(atributo, sizeof(atributo), "População");
            break;
        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            snprintf(atributo, sizeof(atributo), "Área");
            break;
        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            snprintf(atributo, sizeof(atributo), "PIB");
            break;
        case 4:
            valor1 = carta1.densidadePopulacional;
            valor2 = carta2.densidadePopulacional;
            snprintf(atributo, sizeof(atributo), "Densidade Populacional");
            break;
        case 5:
            valor1 = carta1.pibPerCapita;
            valor2 = carta2.pibPerCapita;
            snprintf(atributo, sizeof(atributo), "PIB per capita");
            break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    // Exibir resultado
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, valor1);
    printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, valor2);

    // Determinar a carta vencedora
    int resultado;
    if (opcao == 4) // Densidade populacional: menor vence
        resultado = (valor1 < valor2) ? 1 : (valor2 < valor1) ? 2 : 0;
    else // Demais atributos: maior vence
        resultado = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;

    if (resultado == 1)
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    else if (resultado == 2)
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    else
        printf("Empate!\n");

    return 0;
}
