#include <stdio.h>

// Função para calcular a média dos elementos de um array
float media(int *arr, int tamanho){
  int soma = 0;
  int *p = arr;

  // Soma todos os elementos do array
  for(int i = 0; i<tamanho; i++){
    soma+=*p;
    p++;
  }
  // Retorna a média dos elementos
  return (float)soma/tamanho;
}

int main(){
  
  int array[] = {1,2,3,4,5,6,7,8,9,10};
  int length = sizeof(array)/sizeof(array[0]);
  float resultado;
  
  // Calcula a média do array
  resultado = media(array, length);
  // Imprime o resultado
  printf("A média do array é igual a %.2f", resultado);
  return 0;
}