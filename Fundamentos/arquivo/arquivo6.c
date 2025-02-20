#include <stdio.h>
#include <string.h>

// Função para substituir ocorrências de uma palavra em uma string por outra palavra
void replaceWord(const char *str, const char *palavra_antiga, const char *palavra_nova, char *resultado) {
    char *pos, temp[1000];
    int index = 0;
    int palavra_antigaLen = strlen(palavra_antiga);

    // Loop para encontrar todas as ocorrências da palavra antiga na string
    while ((pos = strstr(str, palavra_antiga)) != NULL) {
        // Copia caracteres do início da string até a posição da palavra antiga
        strncpy(temp, str, pos - str);
        temp[pos - str] = '\0';

        // Adiciona os caracteres copiados ao resultado
        strcpy(&resultado[index], temp);
        index += pos - str;

        // Adiciona a nova palavra ao resultado
        strcpy(&resultado[index], palavra_nova);
        index += strlen(palavra_nova);

        // Move o ponteiro na string original após a palavra antiga
        str = pos + palavra_antigaLen;
    }

    // Copia a parte restante da string original para o resultado
    strcpy(&resultado[index], str);
}

int main() {
    FILE *in, *out;
    char filename[100];
    char conteudo[1000];
    char palavra[100];
    char nova_palavra[100];
    char resultado[1000];

    // Solicita ao usuário o nome do arquivo de entrada
    printf("Digite o nome do arquivo: \n");
    scanf("%s", filename);

    // Abre o arquivo de entrada para leitura
    in = fopen(filename, "r");

    if (in == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        return 1;
    }

    // Solicita ao usuário o nome do arquivo de saída
    printf("Digite o nome do novo arquivo: \n");
    scanf("%s", filename);

    // Abre o arquivo de saída para escrita
    out = fopen(filename, "w");

    if (out == NULL) {
        printf("Erro ao abrir o arquivo\n");
        fclose(in);
        return 1;
    }

    // Solicita ao usuário a palavra a ser substituída
    printf("Digite a palavra a ser substituída: \n");
    scanf("%s", palavra);

    // Solicita ao usuário a nova palavra
    printf("Digite a palavra nova: \n");
    scanf("%s", nova_palavra);

    // Lê o arquivo de entrada linha por linha
    while (fgets(conteudo, sizeof(conteudo), in)) {
        // Substitui ocorrências da palavra antiga pela nova palavra em cada linha
        replaceWord(conteudo, palavra, nova_palavra, resultado);
        // Escreve a linha modificada no arquivo de saída
        fputs(resultado, out);
    }

    // Fecha os arquivos de entrada e saída
    fclose(in);
    fclose(out);

    printf("A substituição foi realizada com sucesso!\n");

    return 0;
}
