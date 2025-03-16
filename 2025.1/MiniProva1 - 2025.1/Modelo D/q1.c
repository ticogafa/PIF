//QUESTÃO 01 (FUNÇÃO E ARRAYS - 1.0 pontos) Crie uma função que receba dois arrays e retorne um novo array contendo a intersecção 
//entre os dois arrays originais. Por exemplo, se tivermos o array A = {1,2,3,4} e o array B = {4,7,3,8}, o array resultante será C =
//{3,4). Assuma que ambos os arrays tenham o mesmo tamanho. Sua função deve:
//    a) Receber três parâmetros: Um inteiro N representando o tamanho dos arrays, e os dois arrays de inteiros;
//    b) Realizar a intersecção entre os arrays A e B recebidos; (
//    c) Imprimir o array final resultante da intersecção. Se não houver elementos em comum aos arrays, a função imprimirá o valor 0;

#include <stdio.h>
#include <stdlib.h>

void function(int n, int A[], int B[]); 

int main() {
    int A[5] = {1, 2, 3, 4, 5};
    int B[5] = {4, 5, 6, 7, 8};
    
    function(5, A, B);
    
    return 0;
}

void function(int n, int A[], int B[]) {
    int C[100];
    int cont = 0; 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                C[cont++] = A[i];
                break; 
            }
        }
    }

    printf("Elementos em comum: ");
    for (int i = 0; i < cont; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

}