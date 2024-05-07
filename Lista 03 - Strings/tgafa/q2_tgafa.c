#include <string.h>
#include <stdio.h>

int main(){
    char frase[51], ch;
    int negrito, italico;

    while ((ch = getchar()) != EOF) {
        negrito = 0;
        italico = 0;
        while (ch != '\n' && ch != EOF) {
            if(ch == '_'){
              if(italico!=0){
                printf("</i>");
                italico-=1;
              }else{
                printf("<i>");
                italico++;
              }
            } else if(ch == '*'){
              if(negrito!=0){
                printf("</b>");
                negrito-=1;
              }else{
                printf("<b>");
                negrito++;
              }
            } else {
                printf("%c", ch);
            }
            ch = getchar();
        }
        if (ch == EOF)
            break;
        printf("\n");
    }
    return 0;
}
