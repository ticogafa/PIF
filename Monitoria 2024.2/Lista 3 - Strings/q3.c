#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//2035 - Projetando camisas
#define ALFABETO 26 
#define MAX_NODES 1000000

typedef struct Node {
    struct Node* filhos[ALFABETO];
    int contagem;
} Node;

Node node_pool[MAX_NODES];
int node_count = 0;

Node* iniciar();
void adicionar_palavra(Node* raiz, char* palavra);
void contar_prefixos(Node* Node1, Node* Node2, int* resposta);
void resolver(int total_palavras);

int main() {
    int total_palavras;
    while (1) {
        scanf("%d", &total_palavras);
        if (total_palavras == -1) break;
        resolver(total_palavras);
    }
    return 0;
}

Node* iniciar() {
    Node* Node = &node_pool[node_count++];
    Node->contagem = 0;
    for (int i = 0; i < ALFABETO; i++) {
        Node->filhos[i] = NULL;
    }
    return Node;
}

void adicionar_palavra(Node* raiz, char* palavra) {
    Node* atual = raiz;
    for (int k = 0; palavra[k] != '\0'; k++) {
        int letra = palavra[k] - 'A';
        if (!atual->filhos[letra]) {
            atual->filhos[letra] = iniciar();
        }
        atual = atual->filhos[letra];
        atual->contagem++;
    }
}

void contar_prefixos(Node* Node1, Node* Node2, int* resposta) {
    if (!Node1 || !Node2) return;
    *resposta += (Node1->contagem < Node2->contagem) ? Node1->contagem : Node2->contagem;
    for (int i = 0; i < ALFABETO; i++) {
        contar_prefixos(Node1->filhos[i], Node2->filhos[i], resposta);
    }
}

void resolver(int total_palavras) {
    Node* raiz1 = iniciar();
    Node* raiz2 = iniciar();
    int resposta = 0;

    for (int i = 0; i < total_palavras; i++) {
        char palavra[100];
        scanf("%s", palavra);
        adicionar_palavra(raiz1, palavra);
    }

    for (int i = 0; i < total_palavras; i++) {
        char palavra[100];
        scanf("%s", palavra);
        adicionar_palavra(raiz2, palavra);
    }

    contar_prefixos(raiz1, raiz2, &resposta);
    printf("%d\n", resposta);

}