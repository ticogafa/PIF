#include <stdio.h>
#include <string.h>

// Função para encontrar o maior prefixo comum entre duas strings
int maior_prefixo_comum(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    return i;
}

int main() {
    int N;
    
    while (1) {
        // a) Receber do usuário o número de jogadores N
        scanf("%d", &N);
        if (N == -1) break;

        // b) Criar arrays para armazenar os sobrenomes das duas equipes
        char sub18[N][101], sub21[N][101];
        
        // c) Preencher os arrays com os sobrenomes fornecidos pelo usuário
        for (int i = 0; i < N; i++) {
            scanf("%s", sub18[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%s", sub21[i]);
        }

        // d) Calcular o número máximo de letras que podem ser impressas nas camisetas
        int max_letras = 0;
        for (int i = 0; i < N; i++) {
            int max_prefixo = 0;
            for (int j = 0; j < N; j++) {
                int prefixo = maior_prefixo_comum(sub18[i], sub21[j]);
                if (prefixo > max_prefixo) {
                    max_prefixo = prefixo;
                }
            }
            max_letras += max_prefixo;
        }

        // e) Imprimir o resultado
        printf("%d\n", max_letras);
    }

    return 0;
}