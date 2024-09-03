#include <stdio.h> 

int main(){
  int num;
  while(1){
    scanf("%d", &num);
    if(num == 0){
      break;
    }
    int matriz[num][num];
    for(int i = 0; i<num; i++){
      for(int j = 0; j<num; j++){
        if(i >= j){
          matriz[i][j] = 1 + i - j;
        }else{
          matriz[i][j] = 1 + j - i;
        }
        printf("%3d", matriz[i][j]);
        if (j < num - 1)
                printf(" ");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}