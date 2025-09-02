#include <stdio.h>

int main() {
    // --- Parte 1: Leitura dos dados do usuário ---
    int n;
    scanf("%d", &n);
    int tamanho_array = n * n;
    int array_de_entrada[tamanho_array]; 
    for (int i = 0; i < tamanho_array; i++) {
        scanf("%d", &array_de_entrada[i]);
    }

    // --- Parte 2: Criação e Preenchimento da Matriz ---
    int matriz[n][n]; 
    int indice_array = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = array_de_entrada[indice_array];
                indice_array++;
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                matriz[i][j] = array_de_entrada[indice_array];
                indice_array++;
            }
        }
    }

    // --- Parte 3: Exibição da Matriz Resultante ---
    printf("\nMatriz Resultante:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0; 
}
