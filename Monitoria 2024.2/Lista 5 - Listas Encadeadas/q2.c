#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Duende 
{
    char nome[21];
    int idade;
    struct Duende* prox;
} Duende;

void insereDuende(Duende** head, char* nome, int idade) 
{
    Duende* novoDuende = (Duende*)malloc(sizeof(Duende));
    strcpy(novoDuende->nome, nome);
    novoDuende->idade = idade;
    novoDuende->prox = NULL;

    if (*head == NULL || (*head)->idade < idade || ((*head)->idade == idade && strcmp((*head)->nome, nome) > 0)) 
    {
        novoDuende->prox = *head;
        *head = novoDuende;
    } else 
    {
        Duende* atual = *head;
        while (atual->prox != NULL && (atual->prox->idade > idade || (atual->prox->idade == idade && strcmp(atual->prox->nome, nome) < 0))) 
        {
            atual = atual->prox;
        }
        novoDuende->prox = atual->prox;
        atual->prox = novoDuende;
    }
}

void distribuirTimes(Duende* head, int N) 
{
    int times = N / 3;
    Duende* lideres[times];
    Duende* entregadores[times];
    Duende* pilotos[times];

    Duende* atual = head;
    for (int i = 0; i < times; i++) 
    {
        lideres[i] = atual;
        atual = atual->prox;
    }
    for (int i = 0; i < times; i++) 
    {
        entregadores[i] = atual;
        atual = atual->prox;
    }
    for (int i = 0; i < times; i++) 
    {
        pilotos[i] = atual;
        atual = atual->prox;
    }

    for (int i = 0; i < times; i++) 
    {
        printf("Time %d\n", i + 1);
        printf("%s %d\n", lideres[i]->nome, lideres[i]->idade);
        printf("%s %d\n", entregadores[i]->nome, entregadores[i]->idade);
        printf("%s %d\n", pilotos[i]->nome, pilotos[i]->idade);
        printf("\n");
    }
}

int main() 
{
    int N;
    scanf("%d", &N);

    Duende* head = NULL;

    for (int i = 0; i < N; i++) 
    {
        char nome[21];
        int idade;
        scanf("%s %d", nome, &idade);
        insereDuende(&head, nome, idade);
    }

    distribuirTimes(head, N);

    Duende* tmp;
    while (head != NULL) 
    {
        tmp = head;
        head = head->prox;
        free(tmp);
    }

    return 0;
}
