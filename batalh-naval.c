#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 5
#define NUM_BARCO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '~';  // ~ representa água
        }
    }
}
// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar os barcos no tabuleiro
void posicionarBarcos(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int barcosPosicionados = 0;
    while (barcosPosicionados < NUM_BARCO) {
        int x = rand() % TAMANHO_TABULEIRO;
        int y = rand() % TAMANHO_TABULEIRO;

        // Verifica se o local está vazio
        if (tabuleiro[x][y] != 'B') {
            tabuleiro[x][y] = 'B'; // B representa o barco
            barcosPosicionados++;
        }
    }
}

// Função para realizar um ataque no tabuleiro
int atacar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) {
        printf("Coordenada inválida! Tente novamente.\n");
        return 0;
    }

    if (tabuleiro[x][y] == 'B') {
        printf("Você acertou um barco!\n");
        tabuleiro[x][y] = 'X';  // X representa um barco afundado
        return 1;
    } else if (tabuleiro[x][y] == '~') {
        printf("Água! Tente novamente.\n");
        tabuleiro[x][y] = 'O';  // O representa uma tentativa errada
        return 0;
    } else {
        printf("Você já atirou nesta posição!\n");
        return 0;
    }
}

int main() {
    char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char tabuleiroInimigo[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int x, y, acertos = 0;

    // Inicializando os tabuleiros
    inicializarTabuleiro(tabuleiroJogador);
    inicializarTabuleiro(tabuleiroInimigo);

    // Posicionando os barcos do inimigo
    posicionarBarcos(tabuleiroInimigo);

    printf("Bem-vindo ao jogo Batalha Naval!\n");
    printf("Objetivo: afundar todos os barcos do inimigo.\n");

    // Loop de jogo
    while (acertos < NUM_BARCO) {
        printf("\nTabuleiro do Inimigo (tente acertar os barcos):\n");
        imprimirTabuleiro(tabuleiroJogador);

        printf("\nDigite as coordenadas (linha e coluna) para atacar (ex: 1 2): ");
        scanf("%d %d", &x, &y);

        if (atacar(tabuleiroInimigo, x, y)) {
            acertos++;
        }

        printf("\nVocê acertou %d de %d barcos.\n", acertos, NUM_BARCO);
    }

    printf("\nParabéns! Você afundou todos os barcos do inimigo!\n");

    return 0;
}

