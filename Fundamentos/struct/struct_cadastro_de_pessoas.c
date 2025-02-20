#include <stdio.h>
#include <string.h>

// Definição da estrutura pessoa
struct pessoa{
  int idade;
  char nome[51];
  long int cpf;
};

// Função para escrever os dados de uma pessoa
void escrever(struct pessoa pessoa){
  printf("Nome da pessoa: %s\n", pessoa.nome);
  printf("Idade da pessoa: %d\n", pessoa.idade);
  printf("CPF da pessoa: %ld", pessoa.cpf);
}

int main(){
  int quantidade;

  // Lê a quantidade de pessoas
  scanf("%d", &quantidade);
  struct pessoa pessoa[quantidade];

  // Lê os dados de cada pessoa
  for(int i = 0; i < quantidade; i++){
    printf("Digite o nome da pessoa número %d\n", i+1);
    scanf("%s", pessoa[i].nome);
    printf("Digite a idade da pessoa número %d\n", i+1);
    scanf("%d", &pessoa[i].idade);
    printf("Digite o CPF da pessoa %d\n", i+1);
    scanf("%ld", &pessoa[i].cpf);
  }

  // Escreve os dados de cada pessoa
  for(int k = 0; k < quantidade; k++){
    printf("\nPessoa %d", k+1);
    printf("\n_______________________\n");
    escrever(pessoa[k]);
    printf("\n_______________________\n");
  }

  return 0;
}