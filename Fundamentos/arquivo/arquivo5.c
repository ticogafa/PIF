#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char linha[256];
    int count = 0;
    char *token;

    // Solicita o nome do arquivo ao usuário
    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);

    // Abre o arquivo para leitura
    file = fopen(filename, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Lê cada linha do arquivo
    while (fgets(linha, sizeof(linha), file)) {
        // Divide a linha em tokens usando delimitadores de espaço, tabulação e nova linha
        token = strtok(linha, " \t\n\r");
        while (token != NULL) {
            count++; // Conta cada palavra
            token = strtok(NULL, " \t\n\r"); // Pega o próximo token
        }
    }

    // Exibe o número total de palavras no arquivo
    printf("O arquivo tem %d palavras\n", count);

    // Fecha o arquivo
    fclose(file);

    return 0;
}