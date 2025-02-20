#include <stdio.h>

int main() {
    FILE *in, *out; // Declaração de ponteiros para arquivos de entrada e saída
    char conteudo[1000]; // Buffer para armazenar o conteúdo lido do arquivo
    char filename[100]; // Buffer para armazenar o nome do arquivo

    // Solicita o nome do arquivo de entrada ao usuário
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", filename);
    
    // Abre o arquivo de entrada no modo de leitura
    in = fopen(filename, "r");

    // Verifica se o arquivo de entrada foi aberto corretamente
    if(in == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1; // Retorna 1 para indicar erro
    }

    // Solicita o nome do arquivo de saída ao usuário
    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", filename);

    // Abre o arquivo de saída no modo de escrita
    out = fopen(filename, "w+");

    // Verifica se o arquivo de saída foi aberto corretamente
    if(out == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1; // Retorna 1 para indicar erro
    }

    // Lê o conteúdo do arquivo de entrada e escreve no arquivo de saída
    while(fgets(conteudo, sizeof(conteudo), in)) {
        fputs(conteudo, out);
    }

    // Informa ao usuário que o arquivo foi copiado com sucesso
    printf("Arquivo copiado com sucesso\n");

    // Fecha os arquivos de entrada e saída
    fclose(in);
    fclose(out);

    return 0; // Retorna 0 para indicar sucesso
}