#include <stdio.h>
#include <string.h>

int ler(int a, int b, int matrix[a][b]) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  return 0;
}
int escrever(int a, int b, int matrix[a][b]) {
  for (int i = 0; i < a; i++) {
    printf("\n");
    for (int j = 0; j < b; j++) {
      printf("[%d]", matrix[i][j]);
    }
  }
  return 0;
}
int multiplicar(int a, int b, int mult[a][b], int c, int matrixA[a][c],
                int matrixB[c][b]) {
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      mult[i][j] = 0;
      for (int k = 0; k < a; k++) {
        mult[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
}
int main() {

  int ia, jaib, jb;
  scanf("%d %d %d", &ia, &jaib, &jb);
  int A[ia][jaib], B[jaib][jb];
  ler(ia, jaib, A);
  ler(jaib, jb, B);

  int C[ia][jb];

  multiplicar(ia, jb, C, jaib, A, B);
  escrever(ia, jb, C);
  return 0;
}