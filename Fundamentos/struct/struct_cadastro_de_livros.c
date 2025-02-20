#include <stdio.h>
#include <string.h> 

struct Livro{
  char nome[100];
  char autor[50];
  int ano;
  float preco;
};

// Função para escrever os detalhes do livro
void escrever(struct Livro livro){
  printf("\n______________________");
  printf("\nNome :%s\n", livro.nome);
  printf("Autor: %s\n", livro.autor);
  printf("Ano: %d\n", livro.ano);
  printf("Preço: %.2f\n", livro.preco);
  printf("\n______________________");
}

int main(){
  int quantidade;
  // Lê a quantidade de livros
  scanf("%d", &quantidade);
  struct Livro livro1[quantidade];
  getchar(); // Limpa o buffer do teclado

  // Loop para ler os detalhes de cada livro
  for(int i = 0; i < quantidade; i++){
    char nome[100], autor[50];
    printf("Digite o nome do livro %d: \n", i);
    fgets(livro1[i].nome, sizeof(livro1[i].nome), stdin);
    strtok(livro1[i].nome, "\n"); // Remove o caractere de nova linha
    printf("Digite o autor do livro %d: \n", i);
    fgets(livro1[i].autor, sizeof(livro1[i].autor), stdin);
    strtok(livro1[i].autor, "\n"); // Remove o caractere de nova linha
    printf("Digite o ano de publicação do livro %d: \n", i);
    scanf("%d", &livro1[i].ano);
    printf("Digite o preço do livro %d: \n", i);
    scanf("%f", &livro1[i].preco);
    getchar(); // Limpa o buffer do teclado
  }

  // Loop para escrever os detalhes de cada livro
  for(int j = 0; j < quantidade; j++){
    escrever(livro1[j]);
  }
  return 0;
}