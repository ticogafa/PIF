#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa um morador com hora, minutos e nome
struct morador {
    int hora;
    int minutos;
    char nome[101];
};

int main() {
    int p, q;
    // Lê os valores de p (tempo limite) e q (quantidade de moradores)
    scanf("%d %d", &p, &q);

    // Aloca dinamicamente um array de structs para armazenar os moradores
    struct morador *moradores = malloc(q * sizeof *moradores);
    int cont = 0; // Contador para o número de moradores que atendem ao critério

    // Loop para ler os dados de cada morador
    for (int i = 0; i < q; i++) {
        char h[6], nome[101];
        int hh, mm;
        // Lê a hora no formato "hh:mm" e o nome do morador
        scanf("%s %s", h, nome);
        // Converte a hora para inteiros (hh e mm)
        sscanf(h, "%d:%d", &hh, &mm);

        // Calcula o total de minutos desde o início do dia
        int total = hh * 60 + mm;
        // Verifica se o morador está dentro do intervalo permitido
        if (total >= 24*60 - p || total <= p) {
            // Ajusta o timestamp para lidar com o intervalo que cruza a meia-noite
            int timestamp = (total <= p) ? total + 24*60 : total;
            moradores[cont].hora    = timestamp; // Armazena a hora ajustada
            moradores[cont].minutos = 0;         // Minutos são fixados em 0
            strcpy(moradores[cont].nome, nome);  // Copia o nome do morador
            cont++;
        }
    }

    // Ordena os moradores selecionados pelo horário usando insertion sort
    for (int i = 1; i < cont; i++) {
        struct morador key = moradores[i];
        int j = i - 1;
        // Compara os horários e ordena em ordem crescente
        while (j >= 0 && (key.hora < moradores[j].hora || 
                         (key.hora == moradores[j].hora && key.minutos < moradores[j].minutos))) {
            moradores[j + 1] = moradores[j];
            j--;
        }
        moradores[j + 1] = key;
    }

    // Imprime os nomes dos moradores ordenados
    for (int i = 0; i < cont; i++) {
        printf("%s\n", moradores[i].nome);
    }

    // Libera a memória alocada dinamicamente
    free(moradores);
    return 0;
}
