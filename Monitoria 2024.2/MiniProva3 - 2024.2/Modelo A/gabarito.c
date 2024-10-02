int new_length(char *str1){
    
    int soma = 0;
    
    for(int i = 0; str1[i] != '\0'; i++){
        
          if((str1[i] >= 'a' && str1[i] <= 'z' ) || (str1[i] >= 'A' && str1[i] <= 'Z')){
              
              soma = soma + str1[i]; 
          }
    }
    
    return soma;

}

