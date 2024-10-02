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
