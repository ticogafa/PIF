//QUESTÃO 01 (MATRIZES E FUNÇÕES - 1.0 PONTOS) Escreva uma função em C que receba uma matriz quadrada 
//de inteiros e um valor V de busca como entrada. A função deve contar quantas vezes aquele valor ocorre na matriz. 
//Caso o valor não seja encontrado, a função deve retornar 0. Sua função deve:
//a) Receber três parâmetros, um inteiro N representando as dimensões da matriz, a matriz de inteiros A[N][N], e o valor V inteiro que deseja-se buscar;
//b) Realizar a busca de V na matriz A[N][N]:
//c) Retornar a quantidade de vezes de v aparece ou 0 caso v não se encontre na matriz A[N][N]:

int contadorDeOcorrencias(int N, int A[N][N], int V) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] == V) {
                count++;
            }
        }
    }
    return count;
}