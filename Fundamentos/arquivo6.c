#include <stdio.h>
#include <string.h>

void replaceWord(const char *str, const char *palavra_antiga, const char *palavra_nova, char *resultado) {
    char *pos, temp[1000];
    int index = 0;
    int palavra_antigaLen = strlen(palavra_antiga);

    while ((pos = strstr(str, palavra_antiga)) != NULL) {
        strncpy(temp, str, pos - str);
        temp[pos - str] = '\0';

        strcpy(&resultado[index], temp);
        index += pos - str;

        strcpy(&resultado[index], palavra_nova);
        index += strlen(palavra_nova);

        str = pos + palavra_antigaLen;
    }

    strcpy(&resultado[index], str);
}

int main() {
    FILE *in, *out;
    char filename[100];
    char conteudo[1000];
    char palavra[100];
    char nova_palavra[100];
    char resultado[1000];

    printf("Digite o nome do arquivo: \n");
    scanf("%s", filename);

    in = fopen(filename, "r");

    if (in == NULL) {
        printf("Não foi possível abrir o arquivo\n");
        return 1;
    }

    printf("Digite o nome do novo arquivo: \n");
    scanf("%s", filename);

    out = fopen(filename, "w");

    if (out == NULL) {
        printf("Erro ao abrir o arquivo\n");
        fclose(in);
        return 1;
    }

    printf("Digite a palavra a ser substituída: \n");
    scanf("%s", palavra);

    printf("Digite a palavra nova: \n");
    scanf("%s", nova_palavra);

    while (fgets(conteudo, sizeof(conteudo), in)) {
        replaceWord(conteudo, palavra, nova_palavra, resultado);
        fputs(resultado, out);
    }

    fclose(in);
    fclose(out);

    printf("A substituição foi realizada com sucesso!\n");

    return 0;
}
