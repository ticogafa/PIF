#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toUpperChar(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

int compareCaseSensitive(const char *str1, const char *str2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (toUpperChar(str1[i]) != toUpperChar(str2[i])) {
            return 1;
        }
    }
    return 0;
}

void handleUserInput();

int num;
char marcador[15];
char frase[60];

int main() {
    while (scanf("%s%d%*c%[^\n]", marcador, &num, frase) != EOF) {
        handleUserInput();
    }

    return 0;
}

void handleUserInput() {
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
            if (toUpperChar(frase[i]) == toUpperChar(marcador[0])) {
                if (compareCaseSensitive(&frase[i], marcador, tamMarcador) == 0) {
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
