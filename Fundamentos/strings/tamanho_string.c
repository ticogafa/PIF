#include <stdio.h>
#include <string.h>

int main(){

  // Declaração da string
  char *s1 = "Tiago";
  
  // Calcula o tamanho da string
  int tamanho = strlen(s1);
  
  // Imprime o tamanho da string
  printf("%d", tamanho);

  return 0;
}