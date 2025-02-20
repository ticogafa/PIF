#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){

    FILE *file;
    char filename[100];
    char linha[256];
    int count = 0;
    char *token;

    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while(fgets(linha, sizeof(linha), file)){
        token = strtok(linha, " \t\n\r");
        while(token != NULL){
            count++;
            token = strtok(NULL, " \t\n\r");
        }
    }

    printf("O arquivo tem %d palavras\n", count);

    fclose(file);

    return 0;
}