#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int *arr; 
    int len, i;

    // solicita o tamanho do vetor ao usuário
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &len);

    // aloca memória para o vetor
    arr = (int*)malloc(len * sizeof(int));
    if (arr == NULL) {
        // Verifica se a alocação de memória falhou
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }

    // lê os elementos do vetor
    for(i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    // imprime os elementos do vetor
    printf("Vetor: ");
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    // libera a memória alocada
    free(arr);

    return 0;
}