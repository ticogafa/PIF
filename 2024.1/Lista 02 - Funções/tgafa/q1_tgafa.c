#include <stdio.h>

int verificar(int n) {
  if (n % 7 == 0)
      return 1;//função que retorna se o número é divisível por 7
  while (n) {
      int r = n % 10;
      n /= 10;
      if (r == 7)
          return 1;//função que retorna se o número possui o algarismo 7
  }
return 0;//caso nenhum acima for verdadeiro, a função retorna falso
}
int main() {
  int n, m, k, palma, ordem, cont = 0;

  while (1) {
      scanf("%d %d %d", &n, &m, &k);
      if (n == 0 && m == 0 && k == 0) {
          break;
      }
      int p = 1;//quando p passar da ordem, o if else no fim do código vai alterar a ordem para descendente
      palma = 0; //ultimo numero da palma vai ser colocado aqui
      ordem = 1; //começa a ordem crescente
      while (1) {
          palma++; //aumenta o número da palma
          if (p == m && verificar(palma)) {
              k--;//vai diminuir k até chegar na k-esima palma que o usuário solicitou
              if (k == 0) { //quando k for igual a zero, chegou a palma desejada
                  printf("%d\n", palma); //imprime a k-esima palma
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
          }//if else if para coloar a ordem como solicitada, por exemplo(1 2 3 4 3 2 1)
      }
    cont++;
      if(cont==100){
      break;
      }//para o código quando chegar no limite de 100 casos de teste de entrada
  }

return 0;
}