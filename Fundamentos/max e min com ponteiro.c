#include <stdio.h>

void maxmin(int *arr, int tamanho, int *min, int *max){
  *min = *arr;
  *max = *arr;
  for(int i = 0; i<tamanho; i++){
    if(*(arr + i)>*max){
      *max = *(arr + i);
      arr++;
    }
    if(*(arr + i)<*min){
      *min = *(arr + i);
      arr++;
    }
  }
}

int main(){
  int max = 0;
  int min = 999999999;
  int array[] = {1,2,3,4,5,6,7,8,9};
  int tamanho = sizeof(array)/sizeof(array[0]);

  maxmin(array, tamanho, &min, &max);

  printf("Máximo: %d\nMínimo: %d\n", max, min);
  return 0;
}