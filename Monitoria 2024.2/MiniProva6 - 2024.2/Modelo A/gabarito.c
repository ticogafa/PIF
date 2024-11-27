//Escreva uma função capaz de multiplicar os elementos de um array de maneira recursiva. Sua função deve 
//percorrer o array do último elemento até o primeiro, multiplicando seus elementos e deve ter a seguinte assinatura:

//long mult_array (int *arr, int N) ;

//Depois, crie um programa que lê o arquivo ENTRADA.txt contendo as informações dos arrays (exemplo abaixo):

//5
//12345
//3
//23 76 87
//10
//987623756712 567890 5632
//
//Onde a primeira linha contém o número de elementos do array e a próxima linha contém os elementos do array em si, 
//separados por espaço. Seu programa deve imprimir na tela o resultado de cada multiplicação dos arrays de entrada.

#include <stdio.h>
#include <stdlib.h>

long mult_array(int *arr, int N) {
    if (N == 0) {
        return 1;
    }
    return arr[N - 1] * mult_array(arr, N - 1);
}

int main() {
    FILE *file = fopen("ENTRADA.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    int N;
    while (fscanf(file, "%d", &N) != EOF) {
        int *arr = (int *)malloc(N * sizeof(int));
        if (arr == NULL) {
            perror("Unable to allocate memory");
            fclose(file);
            return 1;
        }

        for (int i = 0; i < N; i++) {
            fscanf(file, "%d", &arr[i]);
        }

        printf("%ld\n", mult_array(arr, N));
        free(arr);
    }

    fclose(file);
    return 0;
}