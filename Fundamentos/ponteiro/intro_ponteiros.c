#include <stdio.h>
#include <string.h> 

int main(){
  int i = 10;
  int *ponteiro = &i; // ponteiro aponta para o endereço de i
  *ponteiro = 20; // altera o valor de i para 20 através do ponteiro
  printf("%d", *ponteiro); // imprime o valor de i (20)

  int arr[] = {1,2,3,4,5}; // declara um array de inteiros
  int *pont_arr = arr; // ponteiro aponta para o primeiro elemento do array
  printf("\nPrimeiro elemento do array: %d", *pont_arr); // imprime o primeiro elemento do array
  pont_arr++; // incrementa o ponteiro para apontar para o próximo elemento do array
  printf("\nSegundo elemento do array: %d", *pont_arr); // imprime o segundo elemento do array
  return 0;
}
