#include <stdio.h>
#include <string.h>

// Função para verificar se uma palavra está presente no conteúdo do arquivo
int verificar(char content[1000], char palavra[100], FILE *arq)
{
    char *token;

    // Ler o arquivo linha por linha
    while (fgets(content, 1000, arq))
    {
        // Tokenizar a linha usando espaço e nova linha como delimitadores
        token = strtok(content, " \n");
        while (token != NULL)
        {
            // Comparar o token com a palavra
            if (strcmp(token, palavra) == 0)
            {
                return 0; // Palavra encontrada
            }
            token = strtok(NULL, " \n");
        }
    }
    return 1; // Palavra não encontrada
}

int main()
{
    FILE *file;
    char filename[100];
    char conteudo[1000];
    char palavra[100];

    // Solicitar ao usuário que insira o nome do arquivo
    printf("Digite o arquivo que você deseja realizar a busca:\n");
    scanf("%s", filename);

    // Abrir o arquivo no modo de leitura
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo");
        return 1; // Sair se o arquivo não puder ser aberto
    }

    // Solicitar ao usuário que insira a palavra a ser buscada
    printf("Digite a palavra que você deseja buscar:\n");
    scanf("%s", palavra);

    // Chamar a função verificar e imprimir o resultado
    if (verificar(conteudo, palavra, file) == 0)
    {
        printf("A palavra está presente no arquivo");
    }
    else
    {
        printf("A palavra não está presente no arquivo");
    }

    // Fechar o arquivo
    fclose(file);

    return 0;
}