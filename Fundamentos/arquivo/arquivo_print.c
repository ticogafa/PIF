#include <stdio.h>

int main() {
    FILE *file;
    char filename[100];
    char conteudo[100];

    // Solicita ao usuário que insira o nome do arquivo
    printf("Digite o nome do arquivo que você deseja printar o conteudo: \n");
    scanf("%s", filename);

    // Abre o arquivo no modo de leitura
    file = fopen(filename, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }

    // Lê e imprime o conteúdo do arquivo linha por linha
    while (fgets(conteudo, sizeof(conteudo), file)) {
        printf("%s", conteudo);
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}