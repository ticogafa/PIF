
//1306 - Numerando Estradas


#include <stdio.h>

int main() {
    int r, n, cont = 0;

    while (1) {
        cont++;
        scanf("%d %d", &r, &n);
        
        if (r == 0 && n == 0) break;

        if (r > n * 27) {
            printf("Case %d: impossible\n", cont);
        } else {
            int sufixos = (r - 1) / n;
            printf("Case %d: %d\n", cont, sufixos);
        }
    }

    return 0;
}