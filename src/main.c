#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO 10
// Valor que representa o navio
#define NAVIO 3

int main() {
    // Matriz para representar o tabuleiro 10x10
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro preenchendo todas as posições com 0 (água)
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios
    int tamanhoNavio = 3;

    // Coordenadas iniciais dos navios
    // Navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 1;

    // Navio vertical
    int linhaVertical = 5;
    int colunaVertical = 7;

    // Posicionando o navio horizontal
    // Validação para garantir que o navio fique dentro do tabuleiro
    if (colunaHorizontal + tamanhoNavio <= TAMANHO) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: O navio horizontal não cabe no tabuleiro nas coordenadas fornecidas.\n");
        return 1;
    }

    // Posicionando o navio vertical
    // Validação para garantir que o navio fique dentro do tabuleiro e não sobreponha outro navio
    if (linhaVertical + tamanhoNavio <= TAMANHO) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
            } else {
                printf("Erro: Sobreposição detectada ao posicionar o navio vertical.\n");
                return 1;
            }
        }
    } else {
        printf("Erro: O navio vertical não cabe no tabuleiro nas coordenadas fornecidas.\n");
        return 1;
    }

    // Exibe o tabuleiro completo
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Exibe as coordenadas dos navios
    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("(%d, %d)\n", linhaHorizontal, colunaHorizontal + i);
    }

    printf("\nCoordenadas do Navio Vertical:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        printf("(%d, %d)\n", linhaVertical + i, colunaVertical);
    }

    return 0;
}
