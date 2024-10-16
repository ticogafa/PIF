#include <stdio.h>
#include <math.h>

struct circ {
    int x, y;
    int raio;
};

int main() {
    struct circ cacador, flor;
    while (scanf("%d %d %d %d %d %d", &cacador.raio, &cacador.x, &cacador.y, &flor.raio, &flor.x, &flor.y) != EOF) {
        int dx = cacador.x - flor.x;
        int dy = cacador.y - flor.y;
        double d = sqrt(dx * dx + dy * dy);
        
        if (d + flor.raio <= cacador.raio) {
            printf("RICO\n");
        } else {
            printf("MORTO\n");
        }
    }
    return 0;
}