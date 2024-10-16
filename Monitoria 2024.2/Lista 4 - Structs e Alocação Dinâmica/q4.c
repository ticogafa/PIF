#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, D;

    while (scanf("%d %d", &N, &D) != EOF) {
        if (N == 0 && D == 0) {
            break;
        }

        int *attendance = (int *)calloc(N, sizeof(int));

        for (int i = 0; i < D; i++) {
            for (int j = 0; j < N; j++) {
                int attended;
                scanf("%d", &attended);
                if (attended == 1) {
                    attendance[j]++;
                }
            }
        }

        int participou_de_todos = 0;
        for (int j = 0; j < N; j++) {
            if (attendance[j] == D) {
                participou_de_todos = 1;
                break;
            }
        }

        if (participou_de_todos) {
            printf("yes\n");
        } else {
            printf("no\n");
        }

        free(attendance);
    }

    return 0;
}