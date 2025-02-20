#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int n = 0, size;
  char **nomes, tmp[100];

  // Lê o número de nomes
  scanf("%d", &n);

  // Aloca memória para o array de ponteiros
  nomes = (char**)malloc(n * sizeof(char*));

  for (int i = 0; i < n; i++) {
    // Lê um nome temporário
    scanf("%s", tmp);
    size = strlen(tmp);

    // Aloca memória para cada nome
    nomes[i] = (char*)malloc((size + 1) * sizeof(char));

    // Copia o nome temporário para o array de nomes
    strcpy(nomes[i], tmp);
  }

  // Imprime os nomes
  for (int i = 0; i < n; i++) {
    printf("%s\n", nomes[i]);
  }

  // Libera a memória alocada para cada nome
  for (int i = 0; i < n; i++) {
    free(nomes[i]);
  }

  // Libera a memória alocada para o array de ponteiros
  free(nomes);

  return 0;
}