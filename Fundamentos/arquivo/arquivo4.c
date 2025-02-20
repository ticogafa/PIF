#include <stdio.h>

int main(){

    FILE *in, *out;
    char conteudo[1000];
    char filename[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", filename);
    
    in = fopen(filename, "r");

    if(in == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", filename);

    out = fopen(filename, "w+");

    if(out == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while(fgets(conteudo, sizeof(conteudo), in)){
        fputs(conteudo, out);
    }

    printf("Arquivo copiado com sucesso\n");

    fclose(in);
    fclose(out);

    return 0;

}