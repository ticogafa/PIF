#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALFABETO 26
#define MAX_NODES 1000000

typedef struct Node {
    struct Node* filhos[ALFABETO];
    int contagem;
} Node;

Node node_pool[MAX_NODES];
int node_count = 0;

Node* iniciar() {
    Node* no = &node_pool[node_count++];
    no->contagem = 0;
    for (int i = 0; i < ALFABETO; i++) {
        no->filhos[i] = NULL;
    }
    return no;
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

void contar_prefixos(Node* no1, Node* no2, int* resposta) {
    if (!no1 || !no2) return;
    *resposta += (no1->contagem < no2->contagem) ? no1->contagem : no2->contagem;
    for (int i = 0; i < ALFABETO; i++) {
        contar_prefixos(no1->filhos[i], no2->filhos[i], resposta);
    }
}

void liberar(Node* no) {
    // Não é mais necessário liberar nós individualmente
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

    // Não é mais necessário liberar nós individualmente
}

int main() {
    int total_palavras;
    while (1) {
        scanf("%d", &total_palavras);
        if (total_palavras == -1) break;
        resolver(total_palavras);
    }
    return 0;
}