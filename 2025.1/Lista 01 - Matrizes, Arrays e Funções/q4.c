#include <stdio.h>

int verificar(int n) {
  if (n % 7 == 0)
      return 1;
  while (n) {
      int r = n % 10;
      n /= 10;
      if (r == 7)
          return 1;
  }
return 0;
}

int main() {
  int n, m, k, palma, ordem, cont = 0;

  while (1) {
      scanf("%d %d %d", &n, &m, &k);
      if (n == 0 && m == 0 && k == 0) {
          break;
      }
      int p = 1;
      palma = 0;
      ordem = 1;
      while (1) {
          palma++;
          if (p == m && verificar(palma)) {
              k--;
              if (k == 0) {
                  printf("%d\n", palma);
                  break;
              }
          }
          p += ordem;
          if (p > n) {
              p = n - 1;
              ordem = -1;
          } else if (p == 0) {
              p = 2;
              ordem = 1;
          }
      }
    cont++;
      if(cont==100){
      break;
      }
  }

return 0;
}