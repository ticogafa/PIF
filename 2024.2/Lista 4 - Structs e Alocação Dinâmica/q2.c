#include <stdio.h>
#include <math.h>

//3162 - Comunicação espacial
struct nave {
    int x, y, z;
};

double distancia(struct nave a, struct nave b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

char intensidade_sinal(double dist) {
    if (dist <= 20.0) return 'A';
    else if (dist <= 50.0) return 'M';
    else return 'B';
}

int main() {
    int N;
    scanf("%d", &N);
    struct nave naves[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &naves[i].x, &naves[i].y, &naves[i].z);
    }

    for (int i = 0; i < N; i++) {
        double menor_distancia = INFINITY;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                double dist = distancia(naves[i], naves[j]);
                if (dist < menor_distancia) {
                    menor_distancia = dist;
                }
            }
        }
        printf("%c\n", intensidade_sinal(menor_distancia));
    }
    return 0;
}