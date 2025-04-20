//QUESTÃO 1 (STRUCTS E ALOCAÇÃO DINÂMICA - 2.5 PONTOS) Professora Pamela tem uma coleção extensa de mangás 
//(inclusive cerca de 85 volumes só de One Piece) e ela gostaria da ajuda de vocês para criar um programa que 
//gerencia o armazenamento desses mangás em prateleiras. Cada prateleira tem um código (inteiro) e uma cor 
//(string tamanho 20). Por sua vez, cada mangá deve possuir um título (string tamanho 100), autor (string tamanho
//100), um gênero (string tamanho 50), volumes (inteiro), uma variável inteira flag que sinaliza se ela já leu 
//ou não este mangá (flag = 1 significa sim, que ela leu, e flag = 0 é o contrário) e a informação de qual prateleira ele está guardado. 
//Seu programa deve:
//    A) Definir as structs prateleira e mangá de acordo com as informações acima; (0.5 pontos)
//    B) Alocar dinamicamente um array de N mangás, sendo N um valor fornecido pelo usuário, e preenchê-lo com dados de cada mangá, também fornecidos pelo usuário;
//    (0.5 pontos)
//    C) Receber do usuário um gênero e imprimir na tela os títulos não lidos daquele gênero; (0.5 pontos)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A) Definição das structs prateleira e mangá */
typedef struct {
    int  codigo;
    char cor[20];
} Prateleira;

typedef struct {
    char        titulo[100];
    char        autor[100];
    char        genero[50];
    int         volumes;
    int         flag;       /* 1 = lido, 0 = não lido */
    Prateleira  prateleira; /* informação de qual prateleira */
} Manga;

int main() {
    int N;

    /* B) Alocar dinamicamente um array de N mangás */
    printf("Digite o número de mangás na coleção: ");
    scanf("%d", &N);
    Manga *colecao = malloc(N * sizeof(Manga));
    if (colecao == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    /* Preenchendo os dados de cada mangá */
    for (int i = 0; i < N; i++) {
        printf("\n--- Mangá %d de %d ---\n", i+1, N);
        printf("Título: ");
        scanf(" %[^\n]", colecao[i].titulo);

        printf("Autor: ");
        scanf(" %[^\n]", colecao[i].autor);

        printf("Gênero: ");
        scanf(" %[^\n]", colecao[i].genero);

        printf("Número de volumes: ");
        scanf("%d", &colecao[i].volumes);

        printf("Flag (1 = já leu / 0 = não leu): ");
        scanf("%d", &colecao[i].flag);

        printf("Código da prateleira: ");
        scanf("%d", &colecao[i].prateleira.codigo);

        printf("Cor da prateleira: ");
        scanf(" %[^\n]", colecao[i].prateleira.cor);
    }

    /* C) Receber um gênero e imprimir títulos não lidos desse gênero */
    {
        char generoBusca[50];
        printf("\nDigite o gênero para listar títulos NÃO lidos: ");
        scanf(" %[^\n]", generoBusca);
        printf("Mangás do gênero \"%s\" NÃO lidos:\n", generoBusca);
        for (int i = 0; i < N; i++) {
            if (colecao[i].flag == 0
            && strcmp(colecao[i].genero, generoBusca) == 0) {
                printf("  - %s\n", colecao[i].titulo);
            }
        }
    }

    /* D) Receber código de prateleira e imprimir todos os títulos nela */
    {
        int codigoBusca;
        printf("\nDigite o código da prateleira para listar TODOS os títulos nela: ");
        scanf("%d", &codigoBusca);
        printf("Mangás na prateleira %d:\n", codigoBusca);
        for (int i = 0; i < N; i++) {
            if (colecao[i].prateleira.codigo == codigoBusca) {
                printf("  - %s\n", colecao[i].titulo);
            }
        }
    }

    /* E) Liberar toda a memória alocada */
    free(colecao);

    return 0;
}
