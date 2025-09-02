#include <stdio.h>

int main() {
    float temperaturas[7][4];
    float media_turnos[4] = {0};
    int dias_semana[7] = {0,1,2,3,4,5,6};
    int turnos[4] = {0,1,2,3};

// --- Parte 1 e 2: Leitura da Matriz e Cálculo da média ---
    printf("Digite as temperaturas maximas da semana (7 dias x 4 turnos):\n");
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%f", &temperaturas[i][j]);
            media_turnos[j] += temperaturas[i][j];
        }
    }

    // Cálculo das médias por turno
    for (int j = 0; j < 4; j++) {
        media_turnos[j] /= 7.0;
    }

// --- Parte 3: Exibição da Matriz Resultante ---
    for (int turno = 0; turno < 4; turno++) {
        printf("\nTurno: %d - Media: %.1f\n", turnos[turno], media_turnos[turno]);
        int houve_alerta = 0;
        for (int dia = 0; dia < 7; dia++) {
            if (temperaturas[dia][turno] > media_turnos[turno] + 3.0) {
                printf("Alerta de calor: %d\n", dias_semana[dia]);
                houve_alerta = 1;
            }
        }
        if (!houve_alerta) {
            printf("Nenhum dia com alerta de calor\n");
        }
    }

    return 0;
}
