#include <stdio.h>

int main(void){
  int linha, coluna;
  // Lê o número de linhas e colunas da matriz
  scanf("%d %d", &linha, &coluna);
  int a[linha][coluna];
  // Lê os elementos da matriz
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      scanf("%d", &a[i][j]);
    }
  }
  // Imprime a matriz
  for(int i = 0; i < linha; i++){
    printf("\n");
    for(int j = 0; j < coluna; j++){
      printf("[%d]", a[i][j]);
    }
  }
  return 0;
}