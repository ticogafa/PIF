#include <stdio.h>

int main() {
    int N;
    printf("Digite o tamanho da matriz (N): ");
    scanf("%d", &N);

    int matriz[N][N];

    // Preenchendo a matriz com valores fornecidos pelo usuário
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int triangularSuperior = 1;
    int triangularInferior = 1;

    // Verificando se é triangular superior
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (matriz[i][j] != 0) {
                triangularSuperior = 0;
                break;
            }
        }
    }

    // Verificando se é triangular inferior
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (matriz[i][j] != 0) {
                triangularInferior = 0;
                break;
            }
        }
    }

    if (triangularSuperior) {
        printf("S\n");
    } else if (triangularInferior) {
        printf("I\n");
    } else {
        printf("Matriz não triangular\n");
    }

    return 0;
}