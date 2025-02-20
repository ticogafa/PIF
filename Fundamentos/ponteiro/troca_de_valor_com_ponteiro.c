#include <stdio.h>

// Função para trocar os valores de duas variáveis inteiras usando ponteiros
void trocar(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int a = 69, b = 87;

  // Exibe os valores antes da troca
  printf("Valores antes da troca:\na = %d\nb = %d\n", a, b);

  // Chama a função para trocar os valores
  trocar(&a, &b);

  // Exibe os valores depois da troca
  printf("Valores depois da troca:\na = %d\nb = %d\n", a, b);

  return 0;
}