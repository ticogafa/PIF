#include <stdio.h>
#include <string.h>

int main(){

  char str[101], ch = getchar(); // Declaração de variáveis
  int i = 0;

  // Lê caracteres até encontrar uma nova linha
  while(ch!='\n'){
    str[i] = ch;
    // Substitui vogais minúsculas por 'i'
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u'){
      str[i] = 'i';
    // Substitui vogais maiúsculas por 'I'
    } else if(str[i] == 'A' || str[i] == 'E' || str[i] == 'O' || str[i] == 'U'){
        str[i] = 'I';
      }
    i++;
    ch = getchar();
  }
  str[i] = '\0'; // Adiciona o caractere nulo ao final da string
  i = 0;
  printf("%s", str); // Imprime a string modificada
  return 0;
}