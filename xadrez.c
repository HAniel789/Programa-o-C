#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 8

// Estrutura para representar uma peça
typedef struct {
    char tipo;  // K = rei, Q = rainha, R = torre, B = bispo, N = cavalo, P = peão
    char cor;   // 'w' = branco, 'b' = preto
} Peca;

// Tabuleiro de xadrez
Peca tabuleiro[TAM][TAM];

// Inicializa o tabuleiro com as peças na posição inicial
void inicializarTabuleiro() {
    // Inicializa as peças brancas
    tabuleiro[0][0] = (Peca){'R', 'w'};
    tabuleiro[0][1] = (Peca){'N', 'w'};
    tabuleiro[0][2] = (Peca){'B', 'w'};
    tabuleiro[0][3] = (Peca){'Q', 'w'};
    tabuleiro[0][4] = (Peca){'K', 'w'};
    tabuleiro[0][5] = (Peca){'B', 'w'};
    tabuleiro[0][6] = (Peca){'N', 'w'};
    tabuleiro[0][7] = (Peca){'R', 'w'};
    
    for (int i = 0;
