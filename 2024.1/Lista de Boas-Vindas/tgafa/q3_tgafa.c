#include <stdio.h>

int main(void){
  int maior,pos,i,a;
  for(i=0;i<100;i++){
    scanf("%d",&a);
    if(a>maior){
      maior=a;
      pos=i+1;
    }
  }
  printf("%d\n", maior);
  printf("%d\n", pos);
  return 0;
}