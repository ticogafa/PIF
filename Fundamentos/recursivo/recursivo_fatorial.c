#include <stdio.h>

// Função recursiva para calcular o fatorial de um número
int fatorial(int num){
    if(num == 0){ 
        return 1; // Caso base: fatorial de 0 é 1
    }
    else{
        return num * fatorial(num - 1); // Chamada recursiva
    }
}

int main(){
    int numero;
    printf("Digite um número para descobrir seu fatorial: \n");
    scanf("%d", &numero);

    printf("%d", fatorial(numero)); // Exibe o resultado do fatorial
    return 0;
}