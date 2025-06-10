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

void exibirCarta(CartaSuperTrunfo carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("-------------------------------\n");
}

int main() {
    // Cadastro manual de duas cartas
    CartaSuperTrunfo carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 700000.0, 10, 0, 0};
    CartaSuperTrunfo carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.50, 400000.0, 8, 0, 0};
    
    // Calculando dados derivados
    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    // Exibindo as cartas
    printf("==== CARTA 1 ====\n");
    exibirCarta(carta1);

    printf("==== CARTA 2 ====\n");
    exibirCarta(carta2);

    return 0;
}
