#include <stdio.h>

// Definição da estrutura Circulo
struct Circulo {
  int x;
  int y;
  int r;
};

// Função para calcular a área do círculo
float area(int r) { return r * r * 3.14; }

// Função para imprimir os dados do círculo
void printar(struct Circulo c) {
  printf("Ponto X: %d\n", c.x);
  printf("Ponto Y: %d\n", c.y);
  printf("Raio: %d", c.r);
}

int main() {
  struct Circulo circulo1;
  int centro1, centro2, raio;

  // Leitura dos valores de entrada
  scanf("%d %d %d", &centro1, &centro2, &raio);
  circulo1.x = centro1;
  circulo1.y = centro2;
  circulo1.r = raio;

  // Cálculo e impressão da área do círculo
  printf("Área: %.2f\n", area(raio));

  // Impressão dos dados do círculo
  printar(circulo1);

  return 0;
}