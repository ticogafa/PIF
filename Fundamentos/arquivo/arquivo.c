#include <stdio.h>

int main() {
    FILE *arquivo; // Declaração de um ponteiro para o arquivo
    arquivo = fopen("arquivo.txt", "w"); // Abre o arquivo "arquivo.txt" para escrita
    if (arquivo == NULL) { // Verifica se houve erro na abertura do arquivo
        printf("Erro na abertura do arquivo\n"); // Imprime mensagem de erro
        return 1; // Retorna 1 indicando erro
    }
    fprintf(arquivo, "Hello World!\n"); // Escreve "Hello World!" no arquivo
    fclose(arquivo); // Fecha o arquivo
    return 0; // Retorna 0 indicando sucesso
}