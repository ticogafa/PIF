#include <stdio.h>
#include <string.h>

int main(){

  int i = 0;
  char ch = getchar(), str[101];
  while(ch!='\n' && i<100){
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0';
  printf("%s", str);
  return 0;
}