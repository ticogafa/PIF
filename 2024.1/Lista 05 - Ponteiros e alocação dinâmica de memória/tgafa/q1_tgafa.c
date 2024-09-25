#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Camiseta {
  char nome[100]; 
  char cor[10];     
  char tamanho[10]; 
} Camiseta;

int compararCamisetas(const void *a, const void *b) {
  const Camiseta *camiseta1 = (const Camiseta *)a;
  const Camiseta *camiseta2 = (const Camiseta *)b;

  int comparacaoCor = strcmp(camiseta1->cor, camiseta2->cor);
  if (comparacaoCor == 0) {
    int comparacaoTamanho = strcmp(camiseta1->tamanho, camiseta2->tamanho);
    if (comparacaoTamanho == 0) {
      return strcmp(camiseta1->nome, camiseta2->nome);
    } else {
      return comparacaoTamanho;
    }
  } else {
    return comparacaoCor;
  }
}

void ordenarCamisetas(Camiseta *camisetas, int N) {
  for (int i = 1; i < N; ++i) {
    Camiseta atual = camisetas[i];
    int j = i - 1;

    while (j >= 0 && compararCamisetas(&atual, &camisetas[j]) < 0) {
      camisetas[j + 1] = camisetas[j];
      --j;
    }

    camisetas[j + 1] = atual;
  }
}

int main() {
  int N, primeiraTurma = 1;
  Camiseta *camisetas = malloc(sizeof(Camiseta) * 60);

  while (scanf("%d\n", &N) == 1 && N > 0) {
    for (int i = 0; i < N; ++i) {
      scanf("%[^\n]\n%s %s\n", camisetas[i].nome, camisetas[i].cor,
            camisetas[i].tamanho);
    }

    ordenarCamisetas(camisetas, N);

    if (!primeiraTurma) {
      printf("\n");
    }

    for (int i = 0; i < N; ++i) {
      printf("%s %s %s\n", camisetas[i].cor, camisetas[i].tamanho,
            camisetas[i].nome);
    }

    primeiraTurma = 0;
  }

  free(camisetas);
  return 0;
}
