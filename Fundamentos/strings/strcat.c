#include <stdio.h>
#include <string.h>

int main(){

  char s1[101], s2[101], s3[101];
  scanf("%s", s1);
  scanf("%s", s2);
  scanf("%s", s3);
  strcat(s1, s2);
  strcat(s1, s3);
  printf("%s", s1);
  return 0;
}