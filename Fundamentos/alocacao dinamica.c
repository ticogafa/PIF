#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int *arr;
    int len, i;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &len);

    arr = (int*)malloc(len*(sizeof(int)));

    for(i = 0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    printf("Vetor: ");
    for(i = 0; i< len; i++){
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}