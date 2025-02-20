#include <stdio.h>

int main(){
  char string[50];
  scanf("%s", string);
  for(int i = 0; string[i] != '\0'; i++){
    if(string[i] >= 'a' && string[i] <= 'z'){
    string[i] = string[i] - 32; 
  }
  }
  printf("%s", string);
  return 0;
}