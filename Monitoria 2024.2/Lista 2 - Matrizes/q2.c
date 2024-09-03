
//1383 - Sudoku

#include <stdio.h>

int main(){

    int n, i, j, k, l, m, soma, cont = 0;
    int matriz[9][9];

    scanf("%d", &n);

    while(n--){
        cont++;
        soma = 0;
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                for(k = 0; k < 9; k++){
                    if(matriz[i][j] == matriz[i][k] && j != k){
                        soma = 1;
                        break;
                    }
                    if(matriz[i][j] == matriz[k][j] && i != k){
                        soma = 1;
                        break;
                    }
                }
            }
        }

        for(i = 0; i < 9; i += 3){
            for(j = 0; j < 9; j += 3){
                for(k = i; k < i + 3; k++){
                    for(l = j; l < j + 3; l++){
                        for(m = i; m < i + 3; m++){
                            for(int o = j; o < j + 3; o++){
                                if(matriz[k][l] == matriz[m][o] && (k != m || l != o)){
                                    soma = 1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }

        if(soma == 0){
            printf("Instancia %d\nSIM\n\n", cont);
        }else{
            printf("Instancia %d\nNAO\n\n", cont);
        }
    }

    

    return 0;

}