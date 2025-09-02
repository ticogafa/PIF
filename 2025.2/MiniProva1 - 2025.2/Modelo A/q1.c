#include <stdio.h>

int main() {
// --- A) Recebendo os valores do tabuleiro ---
    int tabuleiro[3][3];
    int ganhador = -1;
    int i,j;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &tabuleiro[i][j]);
        }
    }
    // --- B) Verificando linhas e colunas ---
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && 
            tabuleiro[i][1] == tabuleiro[i][2]) { // linhas
            ganhador = tabuleiro[i][0];
        }
        if (tabuleiro[0][j] == tabuleiro[1][j] && 
            tabuleiro[1][j] == tabuleiro[2][j]) { // colunas
            ganhador = tabuleiro[0][i];
        }
    }
    // --- C) Verificando diagonais ---
    if (ganhador == -1) {
        if (tabuleiro[0][0] == tabuleiro[1][1] && 
            tabuleiro[1][1] == tabuleiro[2][2]) { // diag principal
            ganhador = tabuleiro[0][0];
        }

        else if (tabuleiro[0][2] == tabuleiro[1][1] && 
            tabuleiro[1][1] == tabuleiro[2][0]) { // diag secundária
            ganhador = tabuleiro[0][2];
        }
    }
    // --- D) Imprimindo o resultado ---
    if (ganhador == 1) {
        printf("X ganhou\n");
    } else if (ganhador == 0) {
        printf("O ganhou\n");
    } else {
        printf("Empate\n");
    }

    return 0;
}