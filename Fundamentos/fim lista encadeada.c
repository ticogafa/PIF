#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int num;
    struct no *next;
} No;

void inicio(No **head, int valor)
{
    No *new = malloc(sizeof(No));

    if (new)
    {
        (*new).num = valor;
        (*new).next = *head;
        *head = new;
    }
    else
    {
        printf("error");
    }
}

void final(No **head, int valor)
{
    No *new = malloc(sizeof(No));

    if(new){

        (*new).num = valor;
        (*new).next = NULL;

        if(*head == NULL){
            *head = new;
        }else{
            No *aux = *head;
            while((*aux).next != NULL){
                aux = (*aux).next;
            }
            (*aux).next = new;
        }

    }else{
        printf("error");
    }
    
}

void imprimir(No *head)
{
    printf("Lista: ");
    while(head){
        printf("%d ", (*head).num);
        head = (*head).next;
    }
    printf("\n");
}

void freelist(No *head)
{
    No *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = (*head).next;
        free(tmp);
    }
}

void delete_final(No **head){

    if (*head == NULL)
    {
        return;
    }
    No *pen = NULL;
    No *aux = *head;

    while((*aux).next != NULL){
        pen = aux;
        aux = (*aux).next;
    }
    if(pen == NULL){
        free(*head);
        *head = NULL;
        
    }else{
        free(aux);
        pen->next = NULL;
    }
}

int main()
{

    int valor, opcao;
    No *head = NULL;

    do
    {
        printf("Escolha entre as opções abaixo:\n0- Sair\n1- Adicionar no início\n2- Adicionar no final\n3- Imprimir\n4- Remover último elemento\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            inicio(&head, valor);
            break;
        case 2:
            printf("Digite o valor: \n");
            scanf("%d", &valor);
            final(&head, valor);
            break;

        case 3:
            printf("Lista: ");
            imprimir(head);
            break;

        case 4: 
            printf("Último valor removido!\n");
            delete_final(&head);
            break;
        default:
            if (opcao != 0)
            {
                printf("opção inválida");
            }
        }

    } while (opcao != 0);

    freelist(head);

    return 0;
}