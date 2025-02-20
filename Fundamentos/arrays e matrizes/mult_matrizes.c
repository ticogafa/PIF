#include <stdio.h>
#include <string.h>

// Função para ler uma matriz de tamanho a x b
int ler(int a, int b, int matrix[a][b]) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  return 0;
}

// Função para escrever uma matriz de tamanho a x b
int escrever(int a, int b, int matrix[a][b]) {
  for (int i = 0; i < a; i++) {
    printf("\n");
    for (int j = 0; j < b; j++) {
      printf("[%d]", matrix[i][j]);
    }
  }
  return 0;
}

// Função para multiplicar duas matrizes
int multiplicar(int a, int b, int mult[a][b], int c, int matrixA[a][c],
                int matrixB[c][b]) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      mult[i][j] = 0;
      for (int k = 0; k < c; k++) {
        mult[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
  return 0;
}

int main() {
  int ia, jaib, jb;
  scanf("%d %d %d", &ia, &jaib, &jb); // Lê as dimensões das matrizes
  int A[ia][jaib], B[jaib][jb];
  ler(ia, jaib, A); // Lê a matriz A
  ler(jaib, jb, B); // Lê a matriz B

  int C[ia][jb];

  multiplicar(ia, jb, C, jaib, A, B); // Multiplica as matrizes A e B, resultado em C
  escrever(ia, jb, C); // Escreve a matriz resultante C
  return 0;
}