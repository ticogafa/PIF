//QUESTÃO 2  (PONTEIROS - 0.5 pontos) Qual será a saída do seguinte programa:
//
#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4};
    int *p = arr;
    printf("%d %d %d\n", *(p + 1), *p + 2, *(p + 2));
    return 0;
}

//A)2 3 3
//B)1 3 4
//C)1 1 3 
//D)2 2 4
//E)Erro de compilação
//


//Resposta correta: A 