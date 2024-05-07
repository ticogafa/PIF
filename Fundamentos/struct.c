#include <stdio.h>
#include <string.h> 

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

void escrever(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f\n", p.altura);
    printf("\n");
}

int main() {
    struct Pessoa pessoa1, pessoa2;

    printf("Digite o nome da primeira pessoa: ");
    fgets(pessoa1.nome, sizeof(pessoa1.nome), stdin);
    pessoa1.nome[strcspn(pessoa1.nome, "\n")] = '\0'; 
    printf("Digite a idade da primeira pessoa: ");
    scanf("%d", &pessoa1.idade);
    printf("Digite a altura da primeira pessoa: ");
    scanf("%f", &pessoa1.altura);
    getchar(); 

    printf("Digite o nome da segunda pessoa: ");
    fgets(pessoa2.nome, sizeof(pessoa2.nome), stdin);
    pessoa2.nome[strcspn(pessoa2.nome, "\n")] = '\0'; 
    printf("Digite a idade da segunda pessoa: ");
    scanf("%d", &pessoa2.idade);
    printf("Digite a altura da segunda pessoa: ");
    scanf("%f", &pessoa2.altura);

    printf("\nDetalhes da primeira pessoa:\n");
    escrever(pessoa1);

    printf("Detalhes da segunda pessoa:\n");
    escrever(pessoa2);

    return 0;
}
