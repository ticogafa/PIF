#include <stdio.h>

int main() {
    int N;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &N);

    int matriz[N][N];
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int pares = 0, impares = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] % 2 == 0) {
                pares++;
            } else {
                impares++;
            }
        }
    }

    if (pares >= impares) {
        printf("Matriz par\n");
    } else {
        printf("Matriz ímpar\n");
    }

    return 0;
}