//QUESTÃO 01 (MATRIZES E FUNÇÕES - 1.0 PONTOS) Escreva uma função em C que receba uma matriz quadrada de 
//inteiros como entrada e retorne o maior elemento da diagonal principal. Sua função deve:
//a) Receber dois parâmetros: um inteiro N representando as dimensões da matriz e a matriz de inteiro quadrada M[N][N];
//b) Analisar os elementos da diagonal principal;
//c) Retornar um valor inteiro V representando o maior elemento da diagonal principal;

int maiorElementoDiagonalPrincipal(int N, int M[N][N]) {
    int V = M[0][0];
    for (int i = 1; i < N; i++) {
        if (M[i][i] > V) {
            V = M[i][i];
        }
    }
    return V;
}
