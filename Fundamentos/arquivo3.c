#include <stdio.h>

 

int main(){

    char filename[100];
    FILE *file;
    char line[256];
    int LineCount = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    while(fgets(line, sizeof(line), file)){
        LineCount++;
    }

    fclose(file);

    printf("O arquivo %s tem %d linhas\n", filename, LineCount);


    return 0;
}