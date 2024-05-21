#include <stdio.h>

int fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;

    }
    else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(){
    int n;
    printf("\nDigite um numero inteiro: ");
    scanf("%d", &n);
    if(n < 0){
        printf("O numero deve ser maior ou igual a 0\n");
        return 1;
    }else{
        printf("O %d-esimo termo da sequencia de Fibonacci e: %d\n", n, fibonacci(n));
    return 0;
}
    }
    