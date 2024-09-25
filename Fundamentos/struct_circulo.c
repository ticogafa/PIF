#include <stdio.h>

struct Circulo {
  int x;
  int y;
  int r;
};
float area(r) { return r * r * 3.14; }
void printar(struct Circulo c) {
  printf("Ponto X: %d\n", c.x);
  printf("Ponto Y: %d\n", c.y);
  printf("Raio: %d", c.r);
}
int main() {
  struct Circulo circulo1;
  int centro1, centro2, raio;

  scanf("%d %d %d", &centro1, &centro2, &raio);
  circulo1.x = centro1;
  circulo1.y = centro2;
  circulo1.r = raio;
  printf("Área: %.2f\n", area(raio));
  printar(circulo1);

  return 0;
}