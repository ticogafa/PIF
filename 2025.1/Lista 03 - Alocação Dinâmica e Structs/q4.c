#include <stdio.h>
#include <stdlib.h>

int main() {
    int casos;

    // Lê o número de casos de teste
    if (scanf("%d", &casos) != 1) return 0;

    for (int caso = 0; caso < casos; caso++) {
        int numBaldes, numChaves;

        // Lê o número de buckets (M) e o número de chaves (C)
        scanf("%d %d", &numBaldes, &numChaves);

        // Aloca memória para a tabela hash (matriz de ponteiros)
        int **hashTable = malloc(numBaldes * sizeof(int*));
        // Aloca memória para armazenar o número de elementos em cada bucket
        int *tamanhoBalde = calloc(numBaldes, sizeof(int));

        // Inicializa os buckets como NULL e os tamanhos como 0
        for (int i = 0; i < numBaldes; i++) {
            hashTable[i] = NULL;
            tamanhoBalde[i] = 0;
        }

        // Processa cada chave
        for (int i = 0; i < numChaves; i++) {
            int chave;
            scanf("%d", &chave);

            // Calcula o índice do bucket usando a função hash (chave % numBaldes)
            int indexBalde = chave % numBaldes;

            // Realoca memória para adicionar a nova chave no bucket correspondente
            int novoTamanho = tamanhoBalde[indexBalde] + 1;
            int *novoBalde = realloc(hashTable[indexBalde], novoTamanho * sizeof(int));
            if (!novoBalde) {
                perror("Erro ao realocar memória");
                exit(1);
            }
            hashTable[indexBalde] = novoBalde;

            // Adiciona a chave no final do bucket
            hashTable[indexBalde][tamanhoBalde[indexBalde]] = chave;
            tamanhoBalde[indexBalde]++;
        }

        // Imprime um separador entre os casos de teste
        if (caso > 0) 
            printf("\n");

        // Imprime a tabela hash no formato solicitado
        for (int i = 0; i < numBaldes; i++) {
            printf("%d ->", i);
            for (int j = 0; j < tamanhoBalde[i]; j++) {
                printf(" %d ->", hashTable[i][j]);
            }
            printf(" \\\n");
        }

        // Libera a memória alocada para cada bucket
        for (int i = 0; i < numBaldes; i++) {
            free(hashTable[i]);
        }
        // Libera a memória alocada para a tabela hash e os tamanhos dos buckets
        free(hashTable);
        free(tamanhoBalde);
    }

    return 0;
}
