#include <stdio.h>

// Função para encontrar o valor máximo e mínimo em um array
void maxmin(int *arr, int tamanho, int *min, int *max){
  *min = *arr; // Inicializa o mínimo com o primeiro elemento do array
  *max = *arr; // Inicializa o máximo com o primeiro elemento do array
  for(int i = 0; i < tamanho; i++){
    if(*(arr + i) > *max){
      *max = *(arr + i); // Atualiza o máximo se o elemento atual for maior
    }
    if(*(arr + i) < *min){
      *min = *(arr + i); // Atualiza o mínimo se o elemento atual for menor
    }
  }
}

int main(){
  int max = 0;
  int min = 999999999;
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int tamanho = sizeof(array) / sizeof(array[0]);

  // Chama a função maxmin para encontrar os valores máximo e mínimo
  maxmin(array, tamanho, &min, &max);

  // Imprime os valores máximo e mínimo
  printf("Máximo: %d\nMínimo: %d\n", max, min);
  return 0;
}