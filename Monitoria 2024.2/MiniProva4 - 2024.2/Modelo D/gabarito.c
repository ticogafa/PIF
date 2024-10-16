#include <stdio.h>
#include <stdlib.h>

struct livro{ //letra A
    int serial;
    char titulo[50];
    char nome[100];
    int quant;
    float preco;
};


int main()
{
    struct livro *exemplares; //letra B
    int numero;
    char autor[100];
    
    scanf("%d", &numero);
    exemplares = (struct livro *)malloc(numero*sizeof(struct livro));
    
    printf("Cadastrar livros: \n");
    for(int i = 0; i<numero; i++){ //letra C
        
        scanf("%d %s %s %d %f", &exemplares[i].serial, exemplares[i].titulo, exemplares[i].nome, &exemplares[i].quant, &exemplares[i].preco);
        
    }
    
    printf("Digite o nome de um autor:\n"); //letra D
    scanf("%s", autor); 
    
    for(int i = 0; i<numero; i++){
        
        if(strcmp(autor,exemplares[i].nome) == 0){
            printf("Livro encontrado: titulo = %s, quantidade = %d, preço = %f\n", exemplares[i].titulo, exemplares[i].quant, exemplares[i].preco);
        }
    }
    
    
    free(exemplares); //letra E
    

    return 0;
}

/*
OBS - Os alunos podem usar strcmp mesmo que esta não trate os casos de minúsculas e maiúsculas.

Estou usando o exemplo mais simples onde as string de titulo e nome não possuem espaço no meio, 
dai o uso de scanf. Considerar caso o aluno use scanf ou fgets()

*/



/*

(STRUTCS E ALOCAÇÃO DINÂMICA DE MEMÓRIA - 2.0 pontos) Escreva um programa para cadastro de 
livros de uma livraria, definindo uma estrutura chamada livro com as seguintes informações:  
número serial (int), título (string max 50 caracteres), nome do autor (string max 100 caracteres), 
quantidade (int), e preço (float). Seu programa deve receber o número de livros a serem cadastrados 
e alocar dinamicamente um vetor da estrutura livro com este tamanho. Depois deve receber as informações 
do usuário para cada livro cadastrado. Ao final, deve dar a opção de buscar um livro pelo nome do autor 
e imprimir o seu título, a quantidade disponível e o preço. Não esqueça de desalocar a memória alocada 
dinamicamente.

a)Estrutura livro (0.3 pontos);
b)Alocação dinâmica (0.6 pontos);
c)Cadastro dos livros (0.3 pontos);
d)Busca dos livros (0.6 pontos)
e)Liberar a memória (0.2 pontos)


*/