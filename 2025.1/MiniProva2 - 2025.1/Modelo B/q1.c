//QUESTÃO 01  (TAXA DE SIMILARIDADE - 1.5 pontos)  Implemente uma função que, dado duas palavras, é capaz de determinar 
//quantos caracteres estas palavras possuem em comum. Esse número é conhecido como a taxa de similaridade. Por exemplos, 
//as palavras “Comida” e “programação”, possuem taxa de similaridade de 3, uma vez que possuem os carcaters  ‘o’, ‘a’, e ‘m’ em comum. 
//Se as duas palavras forem iguais, a taxa de similaridade será dada pelo tamanho delas. Considerem caracteres minúsculos e 
//maiúsculos com diferentes. 
//Sua função deve:
//A)Receber dois parâmetros, as quais são as duas palavras que deseja-se comparar; (0.25 pontos)
//B)Realizar o cáculo da taxa de similaridade; (0.75 pontos)
//C)Retornar a taxa de similaridade obtida; (0.25 pontos)
//


#include <stdio.h>

int similaridade(char *str1, char *str2) {
    int count = 0;
    if (strcmp(str1, str2) == 0) {
        count = strlen(str1);
    } else {
        int tam1 = strlen(str1);
        int tam2 = strlen(str2);
        for (int i=0; i<tam1; i++) {
            for (int j=0; j<tam2; j++) {
                if(str1[i] == str2[j]) {
                    count++;
                    break;
                }
            }
        }
    }

    return count;
}