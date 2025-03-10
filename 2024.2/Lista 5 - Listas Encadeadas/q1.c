#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char item[21];
    struct Node* next;
} Node;

Node* criarNode(char* item) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    strcpy(novoNode->item, item);
    novoNode->next = NULL;
    return novoNode;
}

int checarDuplo(Node* head, char* item) {
    Node* atual = head;
    while (atual != NULL) {
        if (strcmp(atual->item, item) == 0) {
            return 1;
        }
        atual = atual->next;
    }
    return 0;
}

void inserirOrdenado(Node** head, char* item) {
    if (checarDuplo(*head, item)) {
        return;
    }

    Node* novoNode = criarNode(item);
    if (*head == NULL || strcmp((*head)->item, item) > 0) {
        novoNode->next = *head;
        *head = novoNode;
    } else {
        Node* atual = *head;
        while (atual->next != NULL && strcmp(atual->next->item, item) < 0) {
            atual = atual->next;
        }
        novoNode->next = atual->next;
        atual->next = novoNode;
    }
}

void liberarLista(Node* head) {
    Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void imprimirLista(Node* head) {
    Node* atual = head;
    while (atual != NULL) {
        printf("%s", atual->item);
        if (atual->next != NULL) {
            printf(" ");
        }
        atual = atual->next;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char linha[10001];
        fgets(linha, 10001, stdin);

        linha[strcspn(linha, "\n")] = 0;

        char* token = strtok(linha, " ");
        Node* head = NULL;

        while (token != NULL) {
            inserirOrdenado(&head, token);
            token = strtok(NULL, " ");
        }

        imprimirLista(head);
        liberarLista(head);
    }

    return 0;
}
