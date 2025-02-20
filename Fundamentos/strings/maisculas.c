#include <stdio.h>

int main(){
  char string[50];
  // Lê uma string do usuário
  scanf("%s", string);
  // Converte caracteres minúsculos para maiúsculos
  for(int i = 0; string[i] != '\0'; i++){
    if(string[i] >= 'a' && string[i] <= 'z'){
      string[i] = string[i] - 32; 
    }
  }
  // Imprime a string convertida
  printf("%s", string);
  return 0;
}