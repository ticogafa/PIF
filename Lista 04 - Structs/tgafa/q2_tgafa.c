#include <stdio.h>
#include <string.h>

struct quantidade{

  char nome[51];
  char assinatura[51];
};

int main(void){


  int quantidade = 1, presentes;

  while (1){

    struct quantidade lista[51];
    scanf("%d", &quantidade);
    if (quantidade == 0)
      break;
    for (int i = 0; i < quantidade; i++){

      scanf("%s %s", lista[i].nome, lista[i].assinatura);
    }
    scanf("%d", &presentes);
    int falsificados = 0;
    for (int j = 0; j < presentes; j++){

      char assinatura[51], nome[51];
      scanf("%s %s", nome, assinatura);
      for (int k = 0; k < quantidade; k++){

        if (strcmp(nome, lista[k].nome) == 0){

          int erros = 0;
          for (int _ = 0; lista[k].assinatura[_] != '\0' && assinatura[_] != '\0'; _++){

            if (lista[k].assinatura[_] != assinatura[_]){

              erros++;
            }
          }
          if (erros > 1){

            falsificados++;
          }
        }
      }
    }
    printf("%d\n", falsificados);
  }

  return 0;
}
