#include <stdio.h>
#include <string.h>

int main() {

  char gen, str[1000];
  int n = 0, tam, masc, fem, iguais, tam2;

  while (scanf("%d\n", &tam) != EOF) {//escaneia o tamanho desejado no início do código, encerra se for EOF

    if (n > 0) {
      printf("\n");//Usado no loop a partir do segundo caso
    }
    fgets(str, sizeof(str), stdin);//Recebe string dos tamanhos dos calçados na loja e seus gêneros
    masc = 0;
    fem = 0;
    iguais = 0;//reinicia a quantidade de cada gênero para o próximo caso
    for (int i = 0; i < strlen(str); i += 5) { //avança de 5 em 5 caracteres  
      tam2 = 10 * (str[i] - '0') + (str[i + 1] - '0'); //transforma a string em inteiro, subtraindo os 2 primeiros dígitos do valor de 0 na tabela ascii
      gen = str[i + 3];//pega o caracter de genero, 3 casas na frente do início da entrada

      if (tam2 == tam) {
        iguais++;//se o tamanho dado for igual ao desejado, adiciona +1 na variável de iguais
        if (gen == 'F')
          fem++;//adiciona na variável do gênero feminino
        else
          masc++;//adiciona na variável do gênero masculino
      }
    }
    n++;//adiciona +1 para printar Caso 1:, não foi adicionado antes para não pular a linha em branco que ficará após cada fim de caso
    printf("Caso %d:\n", n);
    printf("Pares iguais: %d\nF: %d\nM: %d", iguais, fem, masc);//print do resultado
  }
  return 0;
}