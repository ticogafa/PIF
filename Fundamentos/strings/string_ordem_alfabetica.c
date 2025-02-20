#include <stdio.h>
#include <string.h>

int main(){

  char str[101], str1[101], str2[101], ch = getchar();
  int i = 0;

  // Lê a primeira string
  while(ch!='\n'){
    str[i] = ch;
    i++;
    ch = getchar();
  }
  str[i] = '\0';
  i = 0;
  
  // Lê a segunda string
  char ch1 = getchar();
  while(ch1!='\n'){
    str1[i] = ch1;
    i++;
    ch1 = getchar();
  }
  str1[i] = '\0';
  i = 0;
  
  // Lê a terceira string
  char ch2 = getchar();
  while(ch2!='\n'){
    str2[i] = ch2;
    i++;
    ch2 = getchar();
  }
  str2[i] = '\0';
  i = 0;

  // Compara as strings e imprime em ordem alfabética
  if(str[0]<str1[0] && str[0]<str2[0]){
    printf("%s\n", str);
    if(str1[0]<str2[0]){
      printf("%s\n", str1);
      printf("%s\n", str2);
    }else{
      printf("%s\n", str2);
      printf("%s\n", str1);
    }
  }else if(str1[0]<str[0] && str1[0]<str2[0]){
    printf("%s\n", str1);
    if(str[0]<str2[0]){
      printf("%s\n", str);
      printf("%s\n", str2);
    }else{
      printf("%s\n", str2);
      printf("%s\n", str);
    }
  }else if(str2[0]<str1[0] && str2[0]<str[0]){
    printf("%s\n", str2);
    if(str1[0]<str[0]){
      printf("%s\n", str1);
      printf("%s\n", str);
    }else{
      printf("%s\n", str);
      printf("%s\n", str1);
    }
  }
  return 0;
}