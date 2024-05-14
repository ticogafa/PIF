#include <stdio.h>

int main(){
    FILE *in, *out;
    char ch;

    in = fopen("arquivo.txt", "r");
    if (in == NULL) {
        printf("Erro na abertura do arquivo\n");
        return 1;
    }
    out = fopen("arquivo2.txt", "w");
    if (out == NULL) {
        printf("Erro na abertura do arquivo\n");
        return 1;
    }
    while(!feof(in)){
        ch = fgetc(in);
        if(!feof(in)&&ch!='\n'){
            fputc(ch, out);
        }
    }
    fclose(in);
    fclose(out);
    return 0;
}