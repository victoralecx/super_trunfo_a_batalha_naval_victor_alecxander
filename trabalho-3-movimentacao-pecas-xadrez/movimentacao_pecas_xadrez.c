```c
#include <stdio.h>

#define TAM 8

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void movimentosTorre(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 0; i < TAM; i++) {
        tabuleiro[i][y] = 1; // coluna
        tabuleiro[x][i] = 1; // linha
    }
    tabuleiro[x][y] = 9; // posição da peça
}

void movimentosBispo(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = -TAM; i < TAM; i++) {
        if (x + i >= 0 && x + i < TAM && y + i >= 0 && y + i < TAM)
            tabuleiro[x + i][y + i] = 1;
        if (x + i >= 0 && x + i < TAM && y - i >= 0 && y - i < TAM)
            tabuleiro[x + i][y - i] = 1;
    }
    tabuleiro[x][y] = 9;
}

void movimentosRainha(int tabuleiro[TAM][TAM], int x, int y) {
    movimentosTorre(tabuleiro, x, y);
    movimentosBispo(tabuleiro, x, y);
}

void movimentosCavalo(int tabuleiro[TAM][TAM], int x, int y) {
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
            tabuleiro[nx][ny] = 1;
        }
    }
    tabuleiro[x][y] = 9;
}

void menu() {
    printf("Escolha a peça para visualizar movimentos:\n");
    printf("1 - Torre\n");
    printf("2 - Bispo\n");
    printf("3 - Rainha\n");
    printf("4 - Cavalo\n");
    printf("0 - Sair\n");
}

int main() {
    int tabuleiro[TAM][TAM];
    int opcao;
    int x, y;

    do {
        menu();
        scanf("%d", &opcao);

        if (opcao == 0) break;

        printf("Digite a posição da peça (linha [0-7] e coluna [0-7]):\n");
        scanf("%d %d", &x, &y);

        limparTabuleiro(tabuleiro);

        switch (opcao) {
            case 1:
                movimentosTorre(tabuleiro, x, y);
                break;
            case 2:
                movimentosBispo(tabuleiro, x, y);
                break;
            case 3:
                movimentosRainha(tabuleiro, x, y);
                break;
            case 4:
                movimentosCavalo(tabuleiro, x, y);
                break;
            default:
                printf("Opção inválida.\n");
                continue;
        }

        printf("\nTabuleiro com movimentos da peça:\n");
        exibirTabuleiro(tabuleiro);

    } while (opcao != 0);

    printf("Programa encerrado.\n");

    return 0;
}
