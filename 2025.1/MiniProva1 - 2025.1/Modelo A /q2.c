//QUESTÃO 2 (ARRAY E FUNÇÕES - 1.0 PONTOS) O processo de projetar uma matriz quadrada NXN em um array N consiste 
//em somar todos os elementos de uma dada coluna] e guardar esta soma na posição j do array. 
//Faça uma função que receba uma matriz NXN do usuário e a projeta em um array N. Sua função deve:
//a) Receber três parâmetros: um inteiro N representando o tamanho da matriz e do array, a matriz quadrada M[N][N], e o array A[N] para projetar a matriz.
//b) Realizar a projeção da matriz:
//c) Imprimir o array final obtido;

#include <stdio.h>

void projetarMatriz(int N, int M[N][N], int A[N]) {
    for (int j = 0; j < N; j++) {
        A[j] = 0;
        for (int i = 0; i < N; i++) {
            A[j] += M[i][j];
        }
    }
}

int main() {
    int N;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &N);

    int M[N][N];
    int A[N];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    projetarMatriz(N, M, A);

    printf("Array projetado:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}