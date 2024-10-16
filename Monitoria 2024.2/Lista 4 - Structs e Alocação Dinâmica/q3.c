#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, M, L, CM, CL, A;

    while (scanf("%d", &N) != EOF) {
        scanf("%d %d", &M, &L);

        int **baralho_do_marcos = (int **)malloc(M * sizeof(int *));
        for (int i = 0; i < M; i++) {
            baralho_do_marcos[i] = (int *)malloc(N * sizeof(int));
        }

        int **baralho_do_leonardo = (int **)malloc(L * sizeof(int *));
        for (int i = 0; i < L; i++) {
            baralho_do_leonardo[i] = (int *)malloc(N * sizeof(int));
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &baralho_do_marcos[i][j]);
            }
        }

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &baralho_do_leonardo[i][j]);
            }
        }

        scanf("%d %d", &CM, &CL);
        scanf("%d", &A);

        int atrib_do_marcos = baralho_do_marcos[CM - 1][A - 1];
        int atrib_do_leonardo = baralho_do_leonardo[CL - 1][A - 1];

        if (atrib_do_marcos > atrib_do_leonardo) {
            printf("Marcos\n");
        } else if (atrib_do_marcos < atrib_do_leonardo) {
            printf("Leonardo\n");
        } else {
            printf("Empate\n");
        }

        for (int i = 0; i < M; i++) {
            free(baralho_do_marcos[i]);
        }
        free(baralho_do_marcos);

        for (int i = 0; i < L; i++) {
            free(baralho_do_leonardo[i]);
        }
        free(baralho_do_leonardo);
    }

    return 0;
}