#include <stdio.h>
#include <string.h>

int main(){

  char str[101], ch = getchar();
  int i = 0, A, B, C, len;

  while(ch!='\n'){
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0';
  len = strnlen(str, 101);
  printf("%s\n", str);
  scanf("%d %d %d", &A, &B, &C);
  char strA[len], strB[len], strC[len];
  int j = 0;
  while(j<len){
    strA[j] = str[j] + A;
    strB[j] = str[j] - B;
    strC[j] = str[j] + C;
    j++;
  }
  strA[j] = '\0';
  strB[j] = '\0';
  strC[j] = '\0';
  printf("%s\n", strA);
  printf("%s\n", strB);
  printf("%s\n", strC);
  
  return 0;
}