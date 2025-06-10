
### 📄 Código: `batalha_naval.c`

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NUM_NAVIOS 3

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~'; // água
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("  ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void posicionarNavios(int navios[NUM_NAVIOS][2]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_NAVIOS; i++) {
        navios[i][0] = rand() % TAM;
        navios[i][1] = rand() % TAM;
    }
}

int verificarAcerto(int linha, int coluna, int navios[NUM_NAVIOS][2]) {
    for (int i = 0; i < NUM_NAVIOS; i++) {
        if (navios[i][0] == linha && navios[i][1] == coluna) {
            return 1; // acerto
        }
    }
    return 0; // erro
}

void habilidadeEspecial(char tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = linha - 1; i <= linha + 1; i++) {
        for (int j = coluna - 1; j <= coluna + 1; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM && tabuleiro[i][j] == '~') {
                tabuleiro[i][j] = '*'; // marcação da área de efeito
            }
        }
    }
}

int main() {
    char tabuleiro[TAM][TAM];
    int navios[NUM_NAVIOS][2];
    int tentativas = 0;
    int acertos = 0;
    int linha, coluna;
    char opcao;

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(navios);

    printf("=== Jogo Batalha Naval ===\n");

    while (acertos < NUM_NAVIOS) {
        exibirTabuleiro(tabuleiro);
        printf("Digite linha e coluna para atacar (ou -1 -1 para usar habilidade especial): ");
        scanf("%d %d", &linha, &coluna);

        if (linha == -1 && coluna == -1) {
            printf("Informe a posição central da habilidade especial: ");
            scanf("%d %d", &linha, &coluna);
            habilidadeEspecial(tabuleiro, linha, coluna);
            continue;
        }

        if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        tentativas++;

        if (verificarAcerto(linha, coluna, navios)) {
            printf(">> ACERTOU um navio!\n");
            tabuleiro[linha][coluna] = 'X';
            acertos++;
        } else {
            printf(">> Água...\n");
            tabuleiro[linha][coluna] = 'O';
        }
    }

    printf("Parabéns! Você afundou todos os navios em %d tentativas.\n", tentativas);

    return 0;
}
