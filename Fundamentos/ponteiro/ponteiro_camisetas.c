#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char *nome;
    char *cor;
    char *tamanho;
} Camiseta;

// Função de comparação para qsort
int comparar(const void *a, const void *b)
{
    Camiseta *cA = (Camiseta *)a;
    Camiseta *cB = (Camiseta *)b;

    if (strcmp(cA->cor, cB->cor) == 0)
    {
        if (strcmp(cA->tamanho, cB->tamanho) == 0)
        {
            return strcmp(cA->nome, cB->nome);
        }
        return -strcmp(cA->tamanho, cB->tamanho);
    }
    return strcmp(cA->cor, cB->cor);
}

int main()
{
    int N, first = 1;
    Camiseta *camisetas = malloc(sizeof(Camiseta) * 60);

    while (scanf("%d\n", &N))
    {
        if (!N)
            break;

        if (first)
            first = 0;
        else
            printf("\n");

        for (int i = 0; i < N; ++i)
        {
            camisetas[i].nome = malloc(100 * sizeof(char));
            camisetas[i].cor = malloc(10 * sizeof(char));
            camisetas[i].tamanho = malloc(10 * sizeof(char));

            scanf("%[^\n]\n", &(camisetas[i].nome));
            scanf("%s %s\n", &(camisetas[i].cor), &(camisetas[i].tamanho));
        }

        // Ordena as camisetas usando qsort
        qsort(camisetas, N, sizeof(Camiseta), comparar);

        for (int i = 0; i < N; ++i)
        {
            printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho, camisetas[i].nome);

            // Libera a memória alocada para cada camiseta
            free(camisetas[i].nome);
            free(camisetas[i].cor);
            free(camisetas[i].tamanho);
        }
    }

    // Libera a memória alocada para o array de camisetas
    free(camisetas);
    return 0;
}
