#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int tripla_pitagorica(int x, int y, int z) {
    int a = x * x;
    int b = y * y;
    int c = z * z;
    return (a + b == c) || (a + c == b) || (b + c == a);
}

int tripla_primitiva(int x, int y, int z) {
    return mdc(mdc(x, y), z) == 1;
}

int main() {
    int x, y, z;
    while (scanf("%d %d %d", &x, &y, &z) == 3) {
        if (tripla_pitagorica(x, y, z)) {
            if (tripla_primitiva(x, y, z)) {
                printf("tripla pitagorica primitiva\n");
            } else {
                printf("tripla pitagorica\n");
            }
        } else {
            printf("tripla\n");
        }
    }
    return 0;
}