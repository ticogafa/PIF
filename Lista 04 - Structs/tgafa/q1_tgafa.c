#include <stdio.h>
#include <string.h>

struct feira {
  char nome[51];
  float preco;
};
int main() {
  int N, M, P, cont;
  struct feira frutas[51];
  float total;

  scanf("%d", &N);
  for (int k = 0; k < N; ++k) {
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
      scanf("%s %f\n", frutas[i].nome, &frutas[i].preco);
    }

    scanf("%d", &P);
    total = 0;
    for (int i = 0; i < P; ++i) {
      char fruta[51];
      scanf("%s %d\n", fruta, &cont);

      for (int j = 0; j < M; ++j) {
        if (strcmp(fruta, frutas[j].nome) == 0) {
          total += cont * frutas[j].preco;
          break;
        }
      }
    }
    printf("R$ %.2f\n", total);
  }
  return 0;
}
