#include <stdio.h>

int main(){

    FILE *file;
    char filename[100];
    char conteudo[100];

    printf("Digite o nome do arquivo que você deseja printar o conteudo: \n");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL){

        printf("Erro ao abrir arquivo");
        return 1;

    }

    while(fgets(conteudo, sizeof(conteudo), file)){
        printf("%s", conteudo);
    }

    return 0;
}