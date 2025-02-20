#include <stdio.h>

void trocar(int *a, int *b){

  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){

  int a = 69, b = 87;

  printf("Valores antes da troca:\na = %d\nb = %d\n", a, b);

  trocar(&a, &b);

  printf("Valores depois da troca:\na = %d\nb = %d\n", a, b);


  return 0;
}