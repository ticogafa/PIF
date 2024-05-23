#include <stdio.h>

int soma(int *arr, int n){
    if(n==0){
        return 0;
    }else{
        return arr[n-1] + soma(arr, n-1);
    }

}

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
}

int main(){

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    print_array(arr, n, 1);
    printf("Soma: %d\n", soma(arr, n));
    print_array(arr, n, 0);
    printf("Soma: %d\n", soma(arr, n));


    return 0;

}