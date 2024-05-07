#include <stdio.h>
#include <string.h> 

int main(){
  int i = 10;
  int *ponteiro = &i;
  *ponteiro = 20;
  printf("%d", *ponteiro);


  int arr[] = {1,2,3,4,5};
  int *pont_arr = arr;
  printf("\nPrimeiro elemento do array: %d", *pont_arr);
  pont_arr++;
  printf("\nSegundo elemento do array: %d", *pont_arr);
  return 0;
}