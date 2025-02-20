#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct no {
    int valor;
    struct no *prox;
} No;

// Função para inserir um nó no início da lista
void inserirnoinicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        (*novo).valor = num;
        (*novo).prox = *lista;
        *lista = novo;
    }else{
        printf("Erro de alocação de memória\n");
    }
}

// Função para inserir um nó no final da lista
void inserirnofinal(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        (*novo).valor = num;
        (*novo).prox = NULL;

        if(*lista == NULL){
            *lista = novo;
        }else{
            No *aux = *lista;
            while((*aux).prox != NULL){
                aux = (*aux).prox;
            }
            (*aux).prox = novo;
        }
    }else{
        printf("Erro de alocação de memória\n");
    }
}

// Função para inserir um nó no meio da lista
void inserirnomeio(No **head, int num, int ant) {
    No *new_node = (No*) malloc(sizeof(No));
    if (new_node == NULL) {
        printf("Erro de alocação de memória\n");
        return;
    }
    (*new_node).valor = num;

    No *current = *head;
    while (current != NULL && (*current).valor != ant) {
        current = (*current).prox;
    }

    if (current == NULL) {
        printf("O valor anterior não foi encontrado\n");
        free(new_node);
        return;
    }

    (*new_node).prox = (*current).prox;
    (*current).prox = new_node;
}

// Função para imprimir a lista
void imprimir(No *no){
    printf("Lista: ");
    while(no){
        printf("%d ", (*no).valor);
        no = (*no).prox;
    }
    printf("\n");
}

int main(){
    int opcao, num, ant;
    No *lista = NULL;

    do{
        printf("\n0 - Sair\n1 - Inserir no início\n2 - Inserir no final\n3 - Inserir no meio\n4 - Imprimir\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um valor\n");
                scanf("%d", &num);
                inserirnoinicio(&lista, num);
                break;
            case 2:
                printf("Digite um valor\n");
                scanf("%d", &num);
                inserirnofinal(&lista, num);
                break;
            case 3:
                printf("Digite um valor\n");
                scanf("%d", &num);
                printf("Digite o valor anterior\n");
                scanf("%d", &ant);
                inserirnomeio(&lista, num, ant);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opcao!=0){
                    printf("Opção inválida\n");
                }
        }
    }while(opcao!=0);

    return 0;
}
