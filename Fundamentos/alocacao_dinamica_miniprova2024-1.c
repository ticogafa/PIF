#include <stdio.h>
#include <stdlib.h>

int *uniao(int *x1, int n1, int *x2, int n2, int *qtd) {
    
    *qtd = n1 + n2; // calcular o tamanho máximo possível da união (soma dos tamanhos)
    
    int *x3 = (int *)malloc(*qtd * sizeof(int)); // cria a variável x3 e aloca memória 
    if (x3 == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1); //tratamento de erro
    }
    
    for (int i = 0; i < n1; i++) {
        x3[i] = x1[i]; // adiciona todos os elementos de x1 em x3
    }

    for (int i = 0; i < n2; i++) {
        x3[n1 + i] = x2[i]; // adiciona todos os elementos de x2 em x3
    } // note que a inserção começa a partir do último elemento adicionado de x1

    return x3;
}

int main() {
    int n1, n2;
    int *x1, *x2, *x3;
    int qtd;
    
    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &n1);
    
    x1 = (int *)malloc(n1 * sizeof(int));
    if (x1 == NULL) {
        printf("Erro na alocação de memória!\n");
        return 1;
    }
    
    printf("Digite os elementos do primeiro vetor:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &x1[i]);
    }
    
    printf("Digite o tamanho do segundo vetor: ");
    scanf("%d", &n2);
    
    x2 = (int *)malloc(n2 * sizeof(int));
    if (x2 == NULL) {
        printf("Erro na alocação de memória!\n");
        free(x1);
        return 1;
    }
    
    printf("Digite os elementos do segundo vetor:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &x2[i]);
    }
    
    x3 = uniao(x1, n1, x2, n2, &qtd);
    
    printf("Vetor resultante da união:\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", x3[i]);
    }
    printf("\n");
    
    free(x1);
    free(x2);
    free(x3);
    
    return 0;
}