#include <stdio.h>

int fatorial(int num){
    if(num == 0){
        return 1;
    }
    else{
        return num*fatorial(num-1);
    }
}

int main(){

    int numero;
    printf("Digite um número para descobrir seu fatorial: \n");
    scanf("%d", &numero);

    printf("%d", fatorial(numero));
    return 0;
}