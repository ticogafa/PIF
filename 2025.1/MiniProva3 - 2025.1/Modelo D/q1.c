//QUESTÃO 1 (STRUCTS E ALOCAÇÃO DINÂMICA) Uma imagem nada mais é do que uma matriz de pixels. 
//Cada pixel é composto por três componentes: R (red), G(green) e B (blue).

//Implemente um programa em C que:

//A) Defina uma struct pixel contendo variáveis inteiras que representam os componentes R, G e B; (0.25 pontos) v
//B) Receba do usuário as dimensões N e M da imagem, aloque dinamicamente uma matriz de struct pixel com dimensões NxM 
//e preencha com valores fornecidos pelo usuário para R, G e B de cada pixel da matriz. (0.5 pontos) v
//C) Receba do usuário um índice da matriz (posição i e j de um pixel), identifique se esse pixel é parte do fundo (ou seja, 
//preto, onde todos os componentes da cor são zero), ou parte da figura geométrica (diferente de zero), imprimindo essa 
//informação ("fundo" ou "figura") na tela; (0.5 pontos)
//D) Receba do usuário uma cor formada por valores para R, G e B e seja capaz de contar o número de pixels dessa cor, 
//imprimindo o resultado na tela; (0.75 pontos)
//E) Libere toda memória alocada dinamicamente. (0.5 pontos)


#include <stdio.h>
#include <stdlib.h>

/* A) Definição da struct pixel com componentes R, G e B */
typedef struct {
    int r;
    int g;
    int b;
} Pixel;

int main() {
    int N, M;

    /* B) Leitura de N e M e alocação dinâmica de uma matriz NxM de Pixels */
    printf("Digite as dimensões da imagem (N M): ");
    if (scanf("%d %d", &N, &M) != 2 || N <= 0 || M <= 0) {
        fprintf(stderr, "Dimensões inválidas.\n");
        return 1;
    }

    /* cria array de N ponteiros para linha */
    Pixel **img = malloc(N * sizeof(Pixel*));
    if (!img) {
        fprintf(stderr, "Falha na alocação de linhas.\n");
        return 1;
    }
    /* para cada linha, aloca M pixels */
    for (int i = 0; i < N; i++) {
        img[i] = malloc(M * sizeof(Pixel));
        if (!img[i]) {
            fprintf(stderr, "Falha na alocação da linha %d.\n", i);
            /* libera o que já tinha sido alocado */
            for (int k = 0; k < i; k++) free(img[k]);
            free(img);
            return 1;
        }
    }

    /* preenchimento dos pixels */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Pixel (%d,%d) — digite R G B: ", i, j);
            scanf("%d %d %d", &img[i][j].r, &img[i][j].g, &img[i][j].b);
        }
    }

    /* C) Verificar se um pixel em (i,j) é fundo (preto) ou figura */
    int i, j;
    printf("\nDigite um índice de pixel para verificar (i j): ");
    scanf("%d %d", &i, &j);
    if (i < 0 || i >= N || j < 0 || j >= M) {
        printf("Índices fora dos limites (0≤i<%d, 0≤j<%d).\n", N, M);
    } else {
        Pixel p = img[i][j];
        if (p.r == 0 && p.g == 0 && p.b == 0)
            printf("Pixel (%d,%d) é parte do FUNDO (preto).\n", i, j);
        else
            printf("Pixel (%d,%d) é parte da FIGURA.\n", i, j);
    }

    /* D) Contar quantos pixels têm uma cor exata R G B */
    int cr, cg, cb, contador = 0;
    printf("\nDigite a cor a buscar (R G B): ");
    scanf("%d %d %d", &cr, &cg, &cb);
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (img[x][y].r == cr
             && img[x][y].g == cg
             && img[x][y].b == cb)
            {
                contador++;
            }
        }
    }
    printf("Existem %d pixel(s) com a cor (%d,%d,%d).\n", contador, cr, cg, cb);

    /* E) Liberar toda a memória alocada */
    for (int x = 0; x < N; x++) {
        free(img[x]);
    }
    free(img);

    return 0;
}
