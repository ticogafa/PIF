#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um problema com criticidade e tipo
typedef struct {
    int criticidade; // Nível de criticidade do problema
    char tipo;       // Tipo do problema ('V' ou 'D')
} Problema;

// Função de comparação para ordenar os problemas
int comparar(const void *a, const void *b) {
    const Problema *p1 = a;
    const Problema *p2 = b;

    // Verifica se os tipos são diferentes
    char tipo1 = p1->tipo;
    char tipo2 = p2->tipo;

    if (tipo1 != tipo2) {
        // 'V' deve vir antes de 'D'
        if (tipo1 == 'V') {
            return -1; // p1 vem antes de p2
        } else {
            return 1; // p2 vem antes de p1
        }
    }

    // Se os tipos são iguais, ordena pela criticidade em ordem decrescente
    int criticidade1 = p1->criticidade;
    int criticidade2 = p2->criticidade;

    return criticidade2 - criticidade1; // Maior criticidade vem primeiro
}

int main() {
    int N, M;
    // Lê o número de linhas (N) e colunas (M) da matriz de problemas
    scanf("%d %d", &N, &M);

    // Aloca dinamicamente memória para armazenar todos os problemas
    Problema *problemas = malloc(N * M * sizeof *problemas);
    int total = N * M; // Total de problemas
    int idx = 0;       // Índice para preencher o array de problemas

    // Lê os problemas da matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char entrada[3]; // Buffer para armazenar a entrada (criticidade e tipo)
            scanf("%2s", entrada);
            problemas[idx].criticidade = entrada[0] - '0'; // Converte o caractere para inteiro
            problemas[idx].tipo       = entrada[1];        // Armazena o tipo
            idx++;
        }
    }

    // Ordena os problemas usando a função de comparação
    qsort(problemas, total, sizeof *problemas, comparar);

    // Imprime os problemas ordenados
    for (int i = 0; i < total; i++) {
        printf("%d%c\n",
               problemas[i].criticidade,
               problemas[i].tipo);
    }

    // Libera a memória alocada
    free(problemas);
    return 0;
}
