#include <stdio.h>
#include <ctype.h>
char vogal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){

    FILE *in, *out;
    in = fopen("lingua.txt", "r");
    if(in == NULL){
        printf("Erro ao abrir o arquivo de entrada\n");
        return 1;
    }
    out = fopen("lingua2.txt", "w");
    if(out == NULL){
        printf("Erro ao abrir o arquivo de saída\n");
        return 1;
    }

    char c;
    while(!feof(in)){
        c = fgetc(in);
        if(vogal(c)){
            fputc('i', out);
        }else{
            fputc(c, out);
        }
    }

    return 0;
}