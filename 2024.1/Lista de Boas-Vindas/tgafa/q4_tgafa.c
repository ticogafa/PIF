#include <stdio.h>

int main(void){
  int n,x,y,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&x,&y);
    if(x>y){
      int s,soma;
      soma = 0;
      s = x-y;
      y+=1;
      for(int j=0;j<s-1;j++){
        if(y%2!=0){
          soma+=y;
        }
        y+=1;
      }
      printf("%d\n",soma);
    }else{
      int s,soma;
      soma = 0;
      s = y-x;
      x+=1;
      for(int j=0;j<s-1;j++){
        if(x%2!=0){
          soma+=x;
        }
        x+=1;
      }
      printf("%d\n",soma);
    }
  }
  return 0;
}