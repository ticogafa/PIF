#include <stdio.h>
#include <string.h>

void compressao(char *str1, char *str2){
    
    int i = 0;
    int j = i+1;
    int k = 0;
    int count = 1;
    
    if(strlen(str1) == 0){
        str2[k] = '0';
        str2[k+1] = '\0';
        
    }else if(strlen(str1) == 1){
        
        str2[k] = str1[i];
        str2[k+1] = '1';
        str2[k+2] = '\0';
    }else{
    
        while(str1[i] != '\0'){
            
            if(str1[i] == str1[j]){                
                    count++;
                    j++;
                    
            }else{ 
                 
                    str2[k] = str1[i];
                    str2[k+1] = (char)(count + 48);
                    count = 1;
                    k = k + 2;
                    
                    i = j;
                    j = i + 1;    
            }
            
        }
        
        str2[k] = '\0';
    }
    
    return;
}
