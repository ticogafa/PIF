#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char status;
    char nome[50];
    struct no *prox;
}No;

int contagem(No *head, char status){
    No *aux = head;
    int cont = 0;
    while(aux != NULL){
        if(aux->status == status){
            cont++;
        }
        aux = aux->prox;
    }
    return cont;
}

void sort(No **head) {
    No *start = *head;
    No *ptr;
    No *tmp = NULL;
    int swapped;

    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr = start;

        while (ptr->prox != tmp) {
            if (strcmp(ptr->nome, ptr->prox->nome) > 0) { 
                char temp_nome[50];
                strcpy(temp_nome, ptr->nome);

                
                strcpy(ptr->nome, ptr->prox->nome);

                
                strcpy(ptr->prox->nome, temp_nome);
 
                swapped = 1;
            }
            ptr = ptr->prox;
        }
        tmp = ptr;
    } while (swapped);
}

void freelist(No *head)
{
    No *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->prox;
        free(tmp);
    }
}

int main(){

    No **head = (No**)malloc(sizeof(No*));
    *head = NULL;  
    char status, nome[50];
    int n;
    scanf("%d", &n);
    getchar();  

    for(int i = 0; i<n; i++){
        scanf("%c", &status);
        getchar();  
        fgets(nome, 50, stdin);  
        nome[strcspn(nome, "\n")] = 0;  
        No *novo = (No*)malloc(sizeof(No));
        novo->status = status;
        strcpy(novo->nome, nome);  
        novo->prox = *head;
        *head = novo;
         
    }

    sort(head);

    No *aux = *head;
    while(aux != NULL){
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }

    printf("Se comportaram: %d | ", contagem(*head, '+'));
    printf("Nao se comportaram: %d\n", contagem(*head, '-'));

    freelist(*head);
    free(head);

    return 0;
}