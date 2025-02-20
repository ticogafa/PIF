#include <stdio.h>

int main(){

    FILE *in, *out; // Declaração de ponteiros para arquivos de entrada e saída
    char filename[100]; // Declaração de um array de caracteres para armazenar o nome do arquivo
    char conteudo[100]; // Declaração de um array de caracteres para armazenar o conteúdo do arquivo

    // Solicita ao usuário o nome do arquivo que deseja copiar
    printf("Digite o nome do arquivo que você deseja copiar: \n");
    scanf("%s", filename);

    // Abre o arquivo de entrada no modo de leitura
    in = fopen(filename, "r");

    // Verifica se o arquivo foi aberto corretamente
    if(in == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1; // Retorna 1 em caso de erro
    }

    // Solicita ao usuário o nome do arquivo onde deseja colar o conteúdo
    printf("Digite o nome do arquivo que você deseja colar o conteúdo: \n");
    scanf("%s", filename);

    // Abre o arquivo de saída no modo de escrita (cria um novo arquivo ou sobrescreve um existente)
    out = fopen(filename, "w+");

    // Verifica se o arquivo foi aberto corretamente
    if(out == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1; // Retorna 1 em caso de erro
    }

    // Lê o conteúdo do arquivo de entrada e escreve no arquivo de saída
    while(fgets(conteudo, sizeof(conteudo), in)){
        fputs(conteudo, out);
    }

    // Mensagem de sucesso
    printf("Arquivo copiado com sucesso!");

    // Fecha os arquivos abertos
    fclose(in);
    fclose(out);

    return 0; // Retorna 0 indicando sucesso
}