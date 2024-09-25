#include <stdio.h>
#include <string.h>

int toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

int compararString(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (toUpper(str1[i]) != toUpper(str2[i])) {
            return 1;
        }
    }
    return 0;
}

int num;
char marcador[15];
char frase[60];

void resolver() {
    int i = 0;
    int tamMarcador = strlen(marcador);

    while (frase[i] != '\0') {
        while (frase[i] != '<' && frase[i] != '\0') {
            putchar(frase[i++]);
        }

        if (frase[i] == '<') {
            putchar(frase[i++]);
        }

        while (frase[i] != '>' && frase[i] != '\0') {
            if (toUpper(frase[i]) == toUpper(marcador[0])) {
                if (compararString(&frase[i], marcador, tamMarcador) == 0) {
                    printf("%d", num);
                    i += tamMarcador;
                } else {
                    putchar(frase[i++]);
                }
            } else {
                putchar(frase[i++]);
            }
        }

        if (frase[i] == '>') {
            putchar(frase[i++]);
        }
    }

    putchar('\n');
}

int main() {
    while (scanf("%s%d", marcador, &num) != EOF) {
        getchar();
        fgets(frase, sizeof(frase), stdin);
        
        size_t len = strlen(frase);
        if (len > 0 && frase[len - 1] == '\n') {
            frase[len - 1] = '\0';
        }
        resolver();
    }

    return 0;
}

