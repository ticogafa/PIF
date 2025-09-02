#include <stdio.h>

int main() {
    // --- A) Leitura do tamanho e preenchimento da matriz ---
    int n;
    scanf("%d", &n);
    int matriz[n][n];
    int tamanho_array = n * n;
    int array_resultante[tamanho_array];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // --- B) Transformação da matriz em array inverso ---
    int k = 0; 
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            array_resultante[k] = matriz[i][j];
            k++;
        }
    }

    // --- C) Exibição do array resultante ---
    printf("\nSaida (Array Resultante):\n");
    for (int i = 0; i < tamanho_array; i++) {
        printf("%d ", array_resultante[i]);
    }
    printf("\n");
    return 0;
}
