#include <stdio.h>

// Função recursiva para somar os elementos de um array
int soma(int *arr, int n){
    if(n==0){
        return 0;
    }else{
        return arr[n-1] + soma(arr, n-1);
    }
}

// Função recursiva para imprimir os elementos de um array
int print_array(int * arr, int n, int forward){
    if(n<=0){
         printf("\n");
    }
    else{
        if (forward == 1){
            printf("%d |", arr[0]);
            print_array(arr+1, n-1, forward);
        }else{
            printf("%d |", arr[n-1]);
            print_array(arr, n - 1, forward);
                
            }
        }
        return 0;
    }

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n, 1); // Imprime o array na ordem normal
    printf("Soma: %d\n", soma(arr, n)); // Imprime a soma dos elementos do array
    print_array(arr, n, 0); // Imprime o array na ordem inversa
    printf("Soma: %d\n", soma(arr, n)); // Imprime a soma dos elementos do array

    return 0;

}
