#include <stdio.h>
#include <string.h>

void main()
{
    char nome[100], sobrenome[100], nomeCompleto[300];
    short casos, i, j, k;
    int contador, tamanhoSobrenome;

    scanf("%hd", &casos);

    while (casos--)
    {
        scanf(" %[^\n] %[^\n]", nome, sobrenome);

        contador = 0;
        i = 0;
        k = 0;
        j = 0;

        tamanhoSobrenome = strlen(sobrenome);

        // Loop que intercala as letras de 'nome' e 'sobrenome'
        while (tamanhoSobrenome--)
        {
            while (nome[i])
            {
                // Adiciona duas letras de 'nome' em 'nomeCompleto'
                nomeCompleto[k++] = nome[i++];
                contador++;

                if (contador == 2)
                    break;
            }

            contador = 0;
            while (sobrenome[j])
            {
                // Adiciona duas letras de 'sobrenome' em 'nomeCompleto'
                nomeCompleto[k++] = sobrenome[j++];
                contador++;

                if (contador == 2)
                    break;
            }

            contador = 0;
        }

        nomeCompleto[k] = '\0';
        printf("%s\n", nomeCompleto);
    }
}