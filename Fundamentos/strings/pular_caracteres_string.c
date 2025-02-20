#include <stdio.h>
#include <string.h>

int main(){

  char str[101], ch = getchar(); // Declaração de variáveis
  int i = 0, A, B, C, len;

  // Leitura de caracteres até encontrar '\n'
  while(ch!='\n'){
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0'; // Finaliza a string
  len = strnlen(str, 101); // Calcula o comprimento da string
  printf("%s\n", str); // Imprime a string original
  scanf("%d %d %d", &A, &B, &C); // Lê os valores de A, B e C
  char strA[len], strB[len], strC[len]; // Declaração de novas strings
  int j = 0;
  
  // Modifica as strings de acordo com os valores de A, B e C
  while(j<len){
    strA[j] = str[j] + A;
    strB[j] = str[j] - B;
    strC[j] = str[j] + C;
    j++;
  }
  strA[j] = '\0'; // Finaliza a string strA
  strB[j] = '\0'; // Finaliza a string strB
  strC[j] = '\0'; // Finaliza a string strC
  printf("%s\n", strA); // Imprime a string modificada strA
  printf("%s\n", strB); // Imprime a string modificada strB
  printf("%s\n", strC); // Imprime a string modificada strC
  
  return 0;
}