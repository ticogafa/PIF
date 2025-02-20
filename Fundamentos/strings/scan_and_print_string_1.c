#include <stdio.h>
#include <string.h>

int main(){

  int i = 0;
  char ch = getchar(), str[101];
  // Lê caracteres até encontrar uma nova linha ou atingir o limite de 100 caracteres
  while(ch!='\n' && i<100){
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0'; // Adiciona o caractere nulo ao final da string
  printf("%s", str); // Imprime a string
  return 0;
}