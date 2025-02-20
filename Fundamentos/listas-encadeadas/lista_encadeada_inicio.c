#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int num;
    struct no *next;
} No;

// Função para inserir um novo nó no início da lista
void inserir(No **head, int valor)
{
    No *new = malloc(sizeof(No));

    if (new){
        (*new).num = valor;
        new->next = *head;
        *head = new;
    }else{
        printf("Não foi possível realizar a alocação");
    }
}

// Função para imprimir todos os elementos da lista
void imprimir(No *head)
{
    No *tmp = head;
    while(tmp != NULL){
        printf("%d ", (*tmp).num);
        tmp = (*tmp).next;
    }
    printf("\n");
}

// Função para liberar a memória alocada para a lista
void freelist(No *head){
    No* tmp;

    while(head!=NULL){
        tmp = head;
        head = (*head).next;
        free(tmp);
    }
}

int main(){
    No *head = NULL;
    int opcao = 1;
    int valor;

    do{
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir(&head, valor);
            break;

        case 2:
            printf("Lista: ");
            imprimir(head);
            break;

        default:
            if (opcao != 0)
            {
                printf("opção inválida");
            }
        }
        
    }while (opcao != 0);
    freelist(head);
    return 0;
}