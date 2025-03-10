//Escreva um programa que insira, em ordem crescente, números inteiros fornecidos pelos usuário em uma lista encadeada. 
//Além disso, o programa deve calcular a soma de todos os elementos inseridos e imprimir o resultado na tela. 
//Para o seu programa, defina:

//A estrutura do nó da lista (0.25);
//A função de inserção na lista (0.7);
//A função que calcula a soma dos elementos da lista (0.25);
//A função main que recebe valores inteiros do usuário e os insere na lista, até que o valor informado pelo usuário 
//seja 0 (zero), depois chama a função para calcular a soma dos valores da lista e imprime esse resultado na tela (0.3);
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{     
    int valor;
    struct node *next;
};


//Critérios - A questão é bem direta, ou o estudante sabe fazer uma struct ou não sabe. 
//Caso simples de erro de sintaxe, podemos reduzir 0.1, contudo erros mais graves de entendimento da questão ou do que são structs levam a zerar a questão. 
//Mais detalhes abaixo:

//Se o aluno descreveu a struct correta, usando typedef ou não = considerar tudo;
//Se o aluno não considerou o ponteiro para o próximo elemento (estrutura autoreferenciada) = reduzir 0.3;
//Se o estudante ainda não sabe como definir uma struct = zerar a questão


void insert (struct node **head, int valor) {
    struct node *tmp = *head, *novo = (struct node*)
            malloc(sizeof(struct node));
    novo->valor = valor;
    novo->next = NULL;

    if (*head == NULL) { //lista vazia
        *head = novo;
    } else {
        // inserção no primeiro elemento
        if (tmp->valor > valor) {
            novo->next = *head;
            *head = novo;
        } else { // caso geral
            while(tmp->next != NULL && tmp->next->valor < valor){
                tmp = tmp->next;
            }
            novo->next = tmp->next;
            tmp->next = novo;
        }
    }
}


//Critérios = o mais importante da questão é o estudante saber implementar os mecanismos necessários para inserir 
//os elementos de maneira ordenada. Os demais componentes são auxiliares. Mais uma vez, aqui deve-se entender a gravidade 
//do erro, se foi um erro simples de sintaxe, algum detalhe que faltou, ou um erro de entendimento completo do 
//processo de inserir em listas encadeadas.

//Não foi feita a criação do novo nó (ou seja, alocação dinâmica e atribuição dos valores passados como parâmetro)  ou 
//a criação está parcialmente correta = reduzir 0.1 a 0.2 dependendo do erro

//Não foi tratado o caso em que o novo nó deve ser inserido no começo da lista = reduzir 0.3

//A lógica de percorrer a lista e adicionar o nó na posição correta (meio ou fim) está errada ou 
//parcialmente errada = reduzir de 0.1 a 0.4 dependendo do erro.

//Não foi tratado o caso de lista vazia = reduzir 0.1


int soma (struct node *head) {
    int soma = 0;
    // pode ser assim ou criar um ponteiro temporario
    while(head != NULL) { 
        soma += head->valor;
        head = head->next;
    }
    return soma;
}
//Critérios = o mais importante da questão é o estudante saber percorrer uma lista encadeada. Os demais componentes são auxiliares. 
//Mais uma vez, aqui deve-se entender a gravidade do erro, se foi um erro simples de sintaxe, algum detalhe que faltou, ou 
//um erro de entendimento completo do processo de percorrer listas encadeadas.


int main() {
    int valor = 0;
    struct node *head = NULL;

    scanf("%d", &valor);
    while (valor != 0) {
        insert(&head, valor);
        scanf("%d", &valor);
    }

    printf("Soma: %d\n", soma(head));
    return 0;
}
//Critérios = aqui o estudante precisa mostrar que entendeu o que se pede no problema. Se sabe definir o critério de parada 
//de inserção e se consegue chamar as funções que ele criou corretamente. 

//Erros de sintaxe, descontar 0.1. 

//Erros na chamada das funções, descontar 0.2. 

