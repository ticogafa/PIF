#include <stdio.h>


void sp(int *s, int *p, int *arr, int tamanho){
  *s = 0;
  *p = 1;

  for(int i = 0; i< tamanho; i++){
  *s+=*(arr + i);
  *p*=*(arr + i);
}
}

int main(){
  int soma, produto;
  int array[] = {1,2,69};
  int length = sizeof(array)/sizeof(array[0]);

  sp(&soma, &produto, array, length);

  printf("A soma é: %d\nO produto é: %d", soma, produto);
  return 0;
}