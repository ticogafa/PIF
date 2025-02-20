#include <stdio.h>
#include <string.h>

int main(){

  char s[100]; // Declara um array de caracteres com tamanho 100
  fgets(s, 100, stdin); // Lê uma string do stdin (entrada padrão) com no máximo 99 caracteres
  printf("%s", s); // Imprime a string lida
  
  return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}