#include <stdio.h>

int main(){

  float M[12][12];
  char O;
  scanf("%s", &O);
  if(O == 'S'){
    float soma = 0;
    for(int i = 0; i<12; i++){
      for(int j = 0; j<12; j++){
        scanf("%f", &M[i][j]);
        if(j>i){
          soma = soma + M[i][j];
        }
      }
    }
    printf("\n%.1f\n", soma);
  }else if(O == 'M'){
    float soma = 0;
    float media;
    for(int i = 0; i<12; i++){
      for(int j = 0; j<12; j++){
        scanf("%f", &M[i][j]);
        if(j>i){
          soma = soma + M[i][j];
        }
      }
    }
    media = soma/66;
    printf("%.1f\n", media);
  }
  return 0;
}