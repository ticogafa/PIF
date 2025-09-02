#include <stdio.h>

int main() {
    int N;
    printf("Digite o número de alunos: ");
    scanf("%d", &N);

    int presencas[N][5];
    int faltas[N];
    int aprovados[N];
    int faltas_dia[5] = {0}; // para contar faltas por coluna

    for (int i = 0; i < N; i++) {
        faltas[i] = 0;
        for (int j = 0; j < 5; j++) {
            scanf("%d", &presencas[i][j]);

            if (presencas[i][j] == 0) {
                faltas[i]++;
                faltas_dia[j]++;
            }
        }
    }

    // Calcula aprovados por presença (75% = no máximo 1 falta em 5 dias)
    for (int i = 0; i < N; i++) {
        if (faltas[i] <= 1) {
            aprovados[i] = 1;
        } else {
            aprovados[i] = 0;
        }
    }

    // Exibe a matriz
    printf("\nMatriz de presenças:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", presencas[i][j]);
        }
        printf("\n");
    }

    // Exibe faltas por aluno
    printf("\nVetor de faltas por aluno:\n");
    for (int i = 0; i < N; i++) {
        printf("Aluno %d: %d faltas\n", i, faltas[i]);
    }

    // Exibe situação de aprovação
    printf("\nAlunos aprovados por presença:\n");
    for (int i = 0; i < N; i++) {
        printf("Aluno %d: %s\n", i, aprovados[i] ? "Aprovado" : "Reprovado");
    }

    return 0;
}
