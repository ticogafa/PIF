//Escreva uma função recursiva que recebe como parâmetros os ponteiros FILE* dos arquivos textos de entrada e saída, 
//e inverte a ordem das linhas do arquivo de entrada, criando o arquivo de saída com as linhas na ordem inversa. 
//Sua função deve ter a seguinte assinatura:

//void inverter_arquivo(FILE *in, FILE *out);

//Depois, crie um programa que abre os arquivos ENTRADA.txt e SAIDA.txt, para leitura e escrita respectivamente, e chama 
//a função recursiva para inverter ENTRADA.txt gerando SAIDA.txt e por fim fecha os arquivos.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024

// Função recursiva para inverter as linhas do arquivo
void inverter_arquivo(FILE **in, FILE **out) {
    char linha[MAX_LINE];
    
    // Lê uma linha do arquivo
    if (fgets(linha, MAX_LINE, *in) != NULL) {
        // Chama recursivamente para ler a próxima linha
        inverter_arquivo(in, out);
        
        // Na volta da recursão, escreve a linha atual
        fprintf(*out, "%s", linha);
    }
}

int main() {
    FILE *entrada = NULL;
    FILE *saida = NULL;
    
    // Abre o arquivo de entrada para leitura
    entrada = fopen("ENTRADA.txt", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir arquivo de entrada!\n");
        return 1;
    }
    
    // Abre o arquivo de saída para escrita
    saida = fopen("SAIDA.txt", "w");
    if (saida == NULL) {
        printf("Erro ao abrir arquivo de saída!\n");
        fclose(entrada);
        return 1;
    }
    
    // Chama a função para inverter o arquivo
    inverter_arquivo(&entrada, &saida);
    
    // Fecha os arquivos
    fclose(entrada);
    fclose(saida);
    
    printf("Arquivo invertido com sucesso!\n");
    return 0;
}