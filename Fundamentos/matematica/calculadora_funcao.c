#include <stdio.h>

float adicao(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        printf("Erro: divisão por zero!\n");
        return 0;
    }
}

int main() {
    float num1, num2;
    char operacao;

    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);

    printf("Digite dois números: ");
    scanf("%f %f", &num1, &num2);

    switch (operacao) {
        case '+':
            printf("Resultado: %.2f\n", adicao(num1, num2));
            break;
        case '-':
            printf("Resultado: %.2f\n", subtracao(num1, num2));
            break;
        case '*':
            printf("Resultado: %.2f\n", multiplicacao(num1, num2));
            break;
        case '/':
            printf("Resultado: %.2f\n", divisao(num1, num2));
            break;
        default:
            printf("Operação inválida!\n");
            break;
    }

    return 0;
}
