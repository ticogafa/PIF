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
        scanf("%d", &N);
        if (N == -1) break;

        char sub18[N][500], sub21[N][500];
        
        for (int i = 0; i < N; i++) {
            scanf("%s", sub18[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%s", sub21[i]);
        }

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

        printf("%d\n", max_letras);
    }

    return 0;
}