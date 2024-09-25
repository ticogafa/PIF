#include <stdio.h>
#include <string.h>

char toLower(char a);

int main() {
    char input[51];
    char cobol[6] = "cobol";

    while(fgets(input, sizeof(input), stdin) != NULL) {
        int len = strlen(input);
        
        if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0'; 
        
        char *caracter = strtok(input, "-");
        int cindex = 0;

        for(int i=0; i<=4 && caracter != NULL; i++) {
            char firstChar = toLower(caracter[0]);
            char lastChar = toLower(caracter[strlen(caracter) - 1]);
            if (firstChar == cobol[cindex] || lastChar == cobol[cindex]) cindex++;
            caracter = strtok(NULL, "-");
        }

        if(cindex == 5) {
            printf("GRACE HOPPER\n");
        } else {
            printf("BUG\n");
        }
    }
        
        
    return 0;
}

char toLower(char a) {
    if(a>='A' && a<='Z') {
        return a-('A'-'a');
    }
    return a;
}