//(STRINGS - 1.5 pontos)  Implemente uma função que conta a ocorrência de uma palavra em um texto, ambos em letras maiúsculas. 
//O primeiro parâmetro da função é um ponteiro para char (string) que representa um texto (conjunto de palavras com caracteres 
//de A à Z separadas por espaços e terminado com '\0') e o segundo parâmetro é um ponteiro para char (string) que representa a 
//palavra a ser pesquisada (composta apenas por caracteres de A à Z e terminada com '\0'). Sua função deve retornar um número inteiro 
//que representa quantas vezes essa palavra aparece no texto. Considere os casos de strings vazias, tanto para a palavra quanto para o 
//texto, casos em que a função deve retornar o valor zero.


#include <stdio.h>
#include <string.h>

int busca(char *texto, char *palavra){

    int i = 0;
    int j = 0;
    int flag = 0;
    int freq = 0;
    
    if(strlen(palavra) == 0 || strlen(texto) == 0){
        
        return 0;
        
    }else{
    
        while(texto[i] != '\0'){
            
            if(texto[i] == palavra[j]){
                j++;
                flag = 1; // começou a contagem
                
                 if(j == (strlen(palavra) - 1)){ //encontrou a palavra
                    freq++;
                    j = 0;
                    flag = 0;
                } 
                
            }else if(texto[i] !=palavra[j] && flag == 1){ //contagem parou no meio
                j = 0;
                flag = 0;
            }
 
            i++;           
        }
    }
        
    return freq;
}
