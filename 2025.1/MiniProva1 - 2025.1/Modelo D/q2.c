//QUESTÃO 2 (MATRIZ E FUNÇÕES - 1.0 pontos) Implemente uma função que rotaciona uma matriz quadrada 90 graus no sentido horário. 
//A figura 1 mostra um exemplo desta rotação. Sua função deve:
//  a) Receber dois parâmetros: um inteiro N representando as dimensões da matriz e a
//  matriz quadrada M[N][N];
//  b) Realizar o processo adequado de rotação;
//  c) Imprimir a matriz resultante da rotação;

#include <stdio.h>


void rotacionar(int N, int M[N][N]) {
    int temp[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[j][N-1-i] = M[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M[i][j] = temp[i][j];
        }
    }
    
    printf("Matriz após rotação de 90 graus:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N = 4;
    int M[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    
    printf("Matriz original:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    
    rotacionar(N, M);
    
    return 0;
}