#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    // Lê o número de elementos na sequência
    if (scanf("%d", &N) != 1) return 0;

    int coluna[65], prox[65];
    // Lê os elementos da sequência inicial
    for (int i = 0; i < N; i++) {
        scanf("%d", &coluna[i]);
    }

    int tamanho = N;
    // Loop para reduzir a sequência até restar apenas um elemento
    while (tamanho > 1) {
        // Compara elementos adjacentes e armazena o resultado em 'prox'
        for (int i = 0; i < tamanho - 1; i++) {
            if (coluna[i] == coluna[i + 1]) {
                prox[i] = 1; // Mesma cor resulta em preta
            } else {
                prox[i] = -1; // Cores diferentes resultam em branca
            }
        }
        // Atualiza a sequência 'coluna' com os valores calculados em 'prox'
        for (int i = 0; i < tamanho - 1; i++) {
            coluna[i] = prox[i];
        }
        // Reduz o tamanho da sequência
        tamanho--;
    }

    // Verifica o último elemento restante para determinar a cor final
    if (coluna[0] == 1)
        printf("preta\n");
    else
        printf("branca\n");

    return 0;
}
