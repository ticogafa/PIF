#include <stdio.h>

int main() {
    char filename[100]; // Array para armazenar o nome do arquivo
    FILE *file; // Ponteiro para o arquivo
    char line[256]; // Array para armazenar cada linha lida do arquivo
    int LineCount = 0; // Variável para contar o número de linhas

    // Solicita ao usuário para digitar o nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);

    // Abre o arquivo no modo de leitura
    file = fopen(filename, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1; // Retorna um código de erro
    }

    // Lê cada linha do arquivo e conta o número de linhas
    while (fgets(line, sizeof(line), file)) {
        LineCount++;
    }

    // Fecha o arquivo
    fclose(file);

    // Imprime o número de linhas no arquivo
    printf("O arquivo %s tem %d linhas\n", filename, LineCount);

    return 0; // Retorna um código de sucesso
}