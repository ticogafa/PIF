#include <stdio.h>
#include <string.h>

int verificar(char content[1000], char palavra[100], FILE *arq)
{
    char *token;

    while (fgets(content, 1000, arq))
    {
        token = strtok(content, " \n");
        while (token != NULL)
        {
            if (strcmp(token, palavra) == 0)
            {
                return 0;
            }
            token = strtok(NULL, " \n");
        }
    }
    return 1;
}

int main()
{
    FILE *file;
    char filename[100];
    char conteudo[1000];
    char palavra[100];

    printf("Digite o arquivo que você deseja realizar a busca:\n");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Digite a palavra que você deseja buscar:\n");
    scanf("%s", palavra);

    if (verificar(conteudo, palavra, file) == 0)
    {
        printf("A palavra está presente no arquivo");
    }
    else
    {
        printf("A palavra não está presente no arquivo");
    }

    fclose(file);

    return 0;
}