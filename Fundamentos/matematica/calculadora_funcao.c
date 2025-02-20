#include <stdio.h>

// Função para realizar a adição
float adicao(float a, float b) {
    return a + b;
}

// Função para realizar a subtração
float subtracao(float a, float b) {
    return a - b;
}

// Função para realizar a multiplicação
float multiplicacao(float a, float b) {
    return a * b;
}

// Função para realizar a divisão
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

    // Solicita ao usuário a operação desejada
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);

    // Solicita ao usuário os dois números
    printf("Digite dois números: ");
    scanf("%f %f", &num1, &num2);

    // Executa a operação escolhida pelo usuário
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
