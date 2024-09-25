#include <stdio.h>

int main(void){
  float a,b,bb,cc,dd,ee,ff;
  
  scanf("%f %f",&a,&b);
  bb = b*4;
  cc = b*4.5;
  dd= b*5;
  ee= b*2;
  ff= b*1.5;
  if(a == 1){
    printf("Total: R$ %.2f\n",bb);
  }else if(a ==2){
    printf("Total: R$ %.2f\n",cc);
  }else if(a ==3){
    printf("Total: R$ %.2f\n",dd);
  }else if(a ==4){
    printf("Total: R$ %.2f\n",ee);
  }else if(a==5){
    printf("Total: R$ %.2f\n",ff);
  }
  return 0;
}