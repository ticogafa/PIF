#include <stdio.h>

int main() {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo\n");
        return 1;
    }
    fprintf(arquivo, "Hello World!\n");
    fclose(arquivo);
    return 0;
}