#include <stdio.h>

int main() {
    int N;

    printf("Digite o tamanho dos arrays: ");
    scanf("%d", &N);

    int arr_1[N], arr_2[N];
    printf("Digite os elementos do primeiro array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr_1[i]);
    }

    printf("Digite os elementos do segundo array:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr_2[i]);
    }

    int arr_3[N];

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            arr_3[i] = arr_1[i];
        } else {
            arr_3[i] = arr_2[i];
        }
    }

    // Exibir o terceiro array
    printf("O terceiro array é:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr_3[i]);
    }
    printf("\n");

    return 0;
}