#include <stdio.h>

int main(){

    FILE *in, *out;
    char filename[100];
    char conteudo[100];

    printf("Digite o nome do arquivo que você deseja copiar: \n");
    scanf("%s", filename);

    in = fopen(filename, "r");

    if(in == NULL){

        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    printf("Digite o nome do arquivo que você deseja colar o conteúdo: \n");
    scanf("%s", filename);

    out = fopen(filename, "w+");

    if(out == NULL){

        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while(fgets(conteudo, sizeof(conteudo), in)){
        fputs(conteudo, out);
    }

    printf("Arquivo copiado com sucesso!");

    return 0;
}