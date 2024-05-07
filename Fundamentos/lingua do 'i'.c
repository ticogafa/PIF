#include <stdio.h>
#include <string.h>

int main(){

  char str[101], ch = getchar();
  int i = 0;

  while(ch!='\n'){
    str[i] = ch;
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u'){
      str[i] = 'i';
    } else if(str[i] == 'A' || str[i] == 'E' || str[i] == 'O' || str[i] == 'U'){
        str[i] = 'I';
      }
    i++;
    ch = getchar();
  }
  str[i] = '\0';
  i = 0;
  printf("%s", str);
  return 0;
}