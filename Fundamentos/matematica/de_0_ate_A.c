#include <stdio.h>

int main(){
  int a, soma = 0;
  // Lê um número inteiro do usuário
  scanf("%d", &a);
  // Soma todos os números de 0 até o número fornecido
  for(int i=0; i<=a; i++){
    soma +=i;
  }
  // Imprime o resultado da soma
  printf("A soma dos números de 0 até %d é: %d", a, soma);
  return 0;
}