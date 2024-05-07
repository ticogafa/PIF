#include <stdio.h>

float media(int *arr, int tamanho){
  int soma = 0;
  int *p = arr;

  for(int i = 0; i<tamanho; i++){
    soma+=*p;
    p++;
  }
  return (float)soma/tamanho;
}

int main(){
  
  int array[] = {1,2,3,4,5,6,7,8,9,10};
  int length = sizeof(array)/sizeof(array[0]);
  float resultado;
  
  resultado = media(array, length);
  printf("A média do array é igual a %.2f", resultado);
  return 0;
}