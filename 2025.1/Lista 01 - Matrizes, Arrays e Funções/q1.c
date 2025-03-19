#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int RPM[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &RPM[i]);
    }

    for (int i = 1; i < N; i++) {
        if (RPM[i] < RPM[i - 1]) {
            printf("%d\n", i + 1);
            return 0;
        }
    }

    printf("0\n");
    return 0;
}