#include <stdio.h>

int main(void){
  int a, b;
  // Lê dois números inteiros
  scanf("%d %d", &a, &b);

  // Verifica qual número é maior e imprime
  if(a > b){
    printf("%d\n", a);
  }else{
    printf("%d\n", b);
  }
  return 0;
}