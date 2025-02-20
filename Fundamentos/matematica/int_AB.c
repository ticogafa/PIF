#include <stdio.h>
int main(void){
   int a, b, soma = 0, dif;
   scanf("%d %d", &a, &b);
   if(a>b){
      dif =a-b;
      printf("%d\n", a);
      for(int i = 0; i<=dif; i++){
         soma+=b;
         b++;
      }
      printf("%d\n", soma);
   }else{
      dif =b-a;
      printf("%d\n", b);
      for(int i = 0; i<=dif; i++){
         soma+=a;
         a++;
      }
      printf("%d\n", soma);
   }
   return 0;
}