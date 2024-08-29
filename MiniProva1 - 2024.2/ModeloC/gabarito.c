#include <stdio.h>

int main() {
    int N;
    printf("Digite o número de alunos: ");
    scanf("%d", &N);

    double notas[N];
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    // Preenchendo o array com notas fornecidas pelo usuário
    printf("Digite as notas dos alunos:\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &notas[i]);
    }

    // Contando os alunos em cada categoria
    for (int i = 0; i < N; i++) {
        if (notas[i] > 9) {
            aprovados++;
        } else if (notas[i] < 3) {
            reprovados++;
        } else if (notas[i] < 7) {
            recuperacao++;
        }
    }

    // Calculando as porcentagens
    double percAprovados = (double)aprovados * 100 / N;
    double percRecuperacao = (double)recuperacao * 100 / N;
    double percReprovados = (double)reprovados * 100 / N;

    // Imprimindo os resultados
    printf("Porcentagem de alunos com nota acima de 9: %.2f%%\n", percAprovados);
    printf("Porcentagem de alunos em recuperação final: %.2f%%\n", percRecuperacao);
    printf("Porcentagem de alunos reprovados: %.2f%%\n", percReprovados);

    return 0;
}