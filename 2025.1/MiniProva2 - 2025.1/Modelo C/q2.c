//QUESTÃO 2  (PONTEIROS - 0.5 pontos) Qual será a saída do seguinte programa:
//
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    int *p = &a;
    *p = *p + b;
    c = *p - b;
    p = &b;
    *p = (*p - c) + (a - *p);
    printf("%d %d %d\n", a, b, c);
    return 0;
}

//A)40 20 30
//B)30 20 10
//C)40 50 20
//D)30 10 40
//E)Erro de compilação
//

//Resposta correta: B