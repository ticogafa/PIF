//QUESTÃO 01 (FUNÇÃO E ARRAYS - 1.0 pontos) Escreva uma função em C que rotaciona os elementos do array 
//para a direita pelo valor R de rotação especificado. Os últimos R elementos devem ser adicionados ao começo. 
//Por exemplo, se o array for {1, 2, 3, 4, 5} e o valor de rotação for R= 2, o array resultante deve ser {4,5, 1, 2, 3). 
//Sua função deve:
//    a) Receber três parâmetros: um array de inteiros A[], um inteiro N representando seu
//    tamanho, e um inteiro R representando o valor de rotação.
//    b) Rotacionar o array para direita pelo valor R de rotação, considerando que os últimos
//    R elementos devem ser adicionados no começo.
//    c) Imprimir o array obtido a partir da rotação.

#include <stdio.h>

void rotacionar(int A[], int N, int R) {
    // Array temporário para armazenar os elementos rotacionados
    int temp[N];

    // Copiar os últimos R elementos para o início do array temporário
    for (int i = 0; i < R; i++) {
        temp[i] = A[N - R + i];
    }

    // Copiar os primeiros N-R elementos para o final do array temporário
    for (int i = 0; i < N - R; i++) {
        temp[R + i] = A[i];
    }

    // Copiar o array temporário de volta para o array original
    for (int i = 0; i < N; i++) {
        A[i] = temp[i];
    }

    // Imprimir o array rotacionado
    printf("Array rotacionado: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    // Definir o array e o valor de rotação
    int A[] = {1, 2, 3, 4, 5};
    int N = 5;
    int R = 2;

    // Chamar a função para rotacionar o array
    rotacionar(A, N, R);

    return 0;
}