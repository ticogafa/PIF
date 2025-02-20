#include <stdio.h>

int main(){
    FILE *in, *out;
    char ch;

    // Abre o arquivo de entrada para leitura
    in = fopen("arquivo.txt", "r");
    if (in == NULL) {
        printf("Erro na abertura do arquivo\n"); // Erro na abertura do arquivo de entrada
        return 1;
    }

    // Abre o arquivo de saída para escrita
    out = fopen("arquivo2.txt", "w");
    if (out == NULL) {
        printf("Erro na abertura do arquivo\n"); // Erro na abertura do arquivo de saída
        return 1;
    }

    // Lê caracteres do arquivo de entrada e escreve no arquivo de saída
    while(!feof(in)){
        ch = fgetc(in);
        if(!feof(in) && ch != '\n'){ // Verifica fim de arquivo e ignora caracteres de nova linha
            fputc(ch, out);
        }
    }

    // Fecha os arquivos de entrada e saída
    fclose(in);
    fclose(out);
    return 0;
}