#include <stdio.h>

int main() {
    int tabuleiro[8][8];
    int peao_linha = -1, peao_coluna = -1;
    int rei_linha = -1, rei_coluna = -1;

    // --- A) Recebendo os valores da matriz ---
    for (int i = 0; i < 8; i++) {
        // Loop para percorrer as colunas do tabuleiro.
        for (int j = 0; j < 8; j++) {
            scanf("%d", &tabuleiro[i][j]);
            if (tabuleiro[i][j] == 1) {
                peao_linha = i;
                peao_coluna = j;
            } else if (tabuleiro[i][j] == 9) {
                rei_linha = i;
                rei_coluna = j;
            }
        }
    }

    // --- B) Verificando se o rei está em xeque ---
    // Condição 1: Rei está na diagonal superior direita do peão.
    int xeque_diagonal_direita = (rei_linha == peao_linha + 1 && rei_coluna == peao_coluna + 1);
    // Condição 2: Rei está na diagonal superior esquerda do peão.
    int xeque_diagonal_esquerda = (rei_linha == peao_linha + 1 && rei_coluna == peao_coluna - 1);
    
    // ---C) Imprimindo "Xeque" se a condição for verdadeira ---
    // Se qualquer uma das condições de xeque for verdadeira...
    if (xeque_diagonal_direita || xeque_diagonal_esquerda) {
        printf("Xeque\n");
    }
    return 0; 
}
