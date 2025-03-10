#include <stdio.h>
#include <stdlib.h>

struct complexa{
    float real;
    float imag;
};
struct complexa soma_array_complexa(struct complexa *A, int N){
    struct complexa resultado = {0, 0};
    for (int i = 0; i < N; i++){
        resultado.real += A[i].real;
        resultado.imag += A[i].imag;
    }

    return resultado;
};
void main(){
    int N;
    struct complexa *array, r;
    scanf("%d", &N);
    array = (struct complexa *)malloc(N * sizeof(struct complexa));
    for (int i = 0; i < N; i++){
        scanf("%f %f", &array[i].real, &array[i].imag);
    }

    r = soma_array_complexa(array, N);
    printf("Somatorio: %f + %fi", r.real, r.imag);

    free(array);
}


/*
(STRUTCS E ALOCAÇÃO DINÂMICA DE MEMÓRIA - 2.0 pontos) Implemente um programa capaz de somar 
um array de números complexos. Os número complexos são caracterizados por possuírem um parte 
real e uma parte imaginária, que é representada por i = -1. Por exemplo, o número  1 + 2i é 
considerado complexo, sendo 1 sua parte real e 2 sua parte imaginária. A soma de dois números 
complexos é dada pela soma de suas partes reais e imaginárias separadamente, por exemplo, 
sejam Z =  a + bi e W = c + di, sua soma será: Z + W = (a+c)  + (b+d)i. Seu programa deve:

a) Criar uma struct chamada complexa a qual contém as partes reais e imaginárias do número (ambas 
do tipo float); (0.3)
b) Criar uma função chamada soma_array_complexa que recebe como parâmetro  um array de struct 
complexa e o seu tamanho N e realiza a soma de todos os seus elementos. Esta função deve, portanto, 
retornar uma variável do tipo struct complexa que representa esse somatório; (0.6)
c) Alocar dinamicamente um array de tamanho N (n fornecido pelo usuário) do tipo struct complexa 
para armazenar vários números complexos fornecidos pelo usuário. (0.6)
d) Realizar a soma de todos os elementos do array, chamando a função soma_array_complexa e imprimir o resultado; (0.3)
e) Liberar a memória alocada dinamicamente; (0.2)


*/