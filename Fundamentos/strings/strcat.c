#include <stdio.h>
#include <string.h>

int main(){

  char s1[101], s2[101], s3[101];
  // Lê a primeira string
  scanf("%s", s1);
  // Lê a segunda string
  scanf("%s", s2);
  // Lê a terceira string
  scanf("%s", s3);
  // Concatena a segunda string com a primeira
  strcat(s1, s2);
  // Concatena a terceira string com a primeira
  strcat(s1, s3);
  // Imprime a string resultante
  printf("%s", s1);
  return 0;
}