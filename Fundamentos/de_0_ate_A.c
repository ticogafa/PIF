#include <stdio.h>

int main(){
  int a, soma = 0;
  scanf("%d", &a);
  for(int i=0; i<=a; i++){
    soma +=i;
  }
  printf("A soma dos números de 0 até %d é: %d", a, soma);
  return 0;
}