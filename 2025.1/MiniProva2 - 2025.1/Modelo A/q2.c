//QUESTÃO 02 (TECLADO QUEBRADO - 1.5 pontos): Prof Pamela estava animada escrevendo um artigo sobre computação quântica e nem percebeu 
//que o teclado de seu computador estava quebrado. Em alguns momentos, caracteres apareciam trocados. O que deveria ser “algoritmo de otimização”, 
//aparecia “%lg@ritm@ d& @timiz%xã@”, ou seja, o ‘a’ era trocado pelo ‘%’, o ‘o’ pelo ‘@’, o ‘e’ pelo ‘&’, e o ‘ç’ por ‘x’. Faça um programa 
//capaz de corrigir um texto fornecido por prof Pamela com base em uma tabela de correlação entre os caracteres certos e errados. 
//Seu programa deve:
//A) Receber uma tabela de correlação entre os caracteres errados presentes do texto e os caracteres corretos que deveriam estar no texto. Essa tabela será uma matriz n x n em que a primeira linha consiste dos caracteres errados e a segunda dos caracteres certos correspondentes. O valor n também será fornecido pelo usuário. Do exemplo acima temos:  (0.5 pontos)
//
//%   @    &    X
//a   o    e    ç
//
//
//B)Receber do usuário o texto que precisa ser corrigido; (0.25 pontos)
//C)Percorrer o texto e fazer as devidas substituições; (0.5 pontos)
//D)Imprimir o texto final corrigido; (0.25 pontos)
//

#include <stdio.h>

int main() {
    int n=0;
    scanf("%d", &n);
    char tabela[2][n];
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
            tabela[i][j] = getchar(); // ou scanf
        }
    }

    char texto[1000];
    gets(texto); // ou scanf
    int tamanho = strlen(texto);
    for (int i=0; i<tamanho; i++) {
        for (int j=0; j<n; j++) {
            if (texto[i] == tabela[0][j]) {
                texto[i] = tabela[1][j];
            }
        }
    }

    puts(texto); // ou printf
    return 0;
}