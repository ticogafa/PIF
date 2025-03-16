//QUESTÃO 2 (MATRIZ E FUNÇÕES - 1.0 pontos) Escreva uma função que calcule a soma dos elementos da diagonal principal e da diagonal secundária de uma matriz quadrada.
//Sua função deve portanto:
//a) Receber dois parâmetros: um inteiro N representando as dimensões da matriz e a matriz de inteiros quadrada M[N][N];
//b) Somar os elementos das diagonais principal e secundárias;
//c)Retornar um valor inteiro representando a soma de ambas as diagonais;

int soma_diagonais(int N, int M[N][N]) {
    int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += M[i][i]; // Diagonal principal
        soma += M[i][N - 1 - i]; // Diagonal secundária
    }
    return soma;
}