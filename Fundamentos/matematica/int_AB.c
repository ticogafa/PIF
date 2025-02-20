#include <stdio.h>

int main(void){
   int a, b, soma = 0, dif;
   scanf("%d %d", &a, &b); // Lê dois inteiros a e b
   if(a > b){
      dif = a - b; // Calcula a diferença entre a e b
      printf("%d\n", a); // Imprime o valor de a
      for(int i = 0; i <= dif; i++){
         soma += b; // Soma o valor de b à variável soma
         b++; // Incrementa b
      }
      printf("%d\n", soma); // Imprime o valor da soma
   } else {
      dif = b - a; // Calcula a diferença entre b e a
      printf("%d\n", b); // Imprime o valor de b
      for(int i = 0; i <= dif; i++){
         soma += a; // Soma o valor de a à variável soma
         a++; // Incrementa a
      }
      printf("%d\n", soma); // Imprime o valor da soma
   }
   return 0;
}