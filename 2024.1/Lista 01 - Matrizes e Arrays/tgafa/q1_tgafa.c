#include <stdio.h>

int main() {
  int numero;
  int par[5];
  int impar[5];
  int n2 = 0, n1 = 0;
  for(int i = 0; i<15; i++){
    scanf("%d", &numero);
    if(numero%2!=0){
      impar[n2]=numero;
      n2++;
      if(n2 == 5){
        for(int k = 0; k<5; k++){
          printf("impar[%d] = %d\n", k, impar[k]);
        }
        n2 = 0;
        int impar[5];
      }
    }else{
      par[n1] = numero;
      n1++;
      if(n1 == 5){
        for(int k = 0; k<5; k++){
          printf("par[%d] = %d\n", k, par[k]);
        }
        n1 = 0;
        int par[5];
      }
    }
  }
  for(int p = 0; p<n2; p++){
    printf("impar[%d] = %d\n", p, impar[p]);
  }
  for(int p = 0; p<n1; p++){
    printf("par[%d] = %d\n", p, par[p]);
  }
  return 0;
}