#include <stdio.h>
#include <ctype.h>

// Função para verificar se um caractere é uma vogal
char vogal(char c) {
    c = tolower(c); // Converte o caractere para minúsculo
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; // Verifica se é uma vogal
}

int main() {
    FILE *in, *out;

    // Abre o arquivo de entrada para leitura
    in = fopen("lingua.txt", "r");
    if (in == NULL) {
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1; // Retorna erro se não conseguir abrir o arquivo
    }

    // Abre o arquivo de saída para escrita
    out = fopen("lingua2.txt", "w");
    if (out == NULL) {
        printf("Erro ao abrir o arquivo de saída\n");
        return 1; // Retorna erro se não conseguir abrir o arquivo
    }

    char c;
    // Lê o arquivo de entrada caractere por caractere até o final do arquivo
    while (!feof(in)) {
        c = fgetc(in); // Lê um caractere do arquivo de entrada
        if (vogal(c)) {
            fputc('i', out); // Se for uma vogal, escreve 'i' no arquivo de saída
        } else {
            fputc(c, out); // Caso contrário, escreve o próprio caractere no arquivo de saída
        }
    }

    // Fecha os arquivos
    fclose(in);
    fclose(out);

    return 0; // Retorna sucesso
}