void only_alpha_num(char *str1, char *str2){
    
    int i = 0;
    int j = 0;
    
    while(str1[i] != '\0'){
        
        if((str1[i] >= 'a' && str1[i] <= 'z' ) || (str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= '0' && str1[i] <= '9')){
            
            str2[j] = str1[i];
            j++;
            
        }
        
        i++;
    }
    
    str2[j] ='\0';
}
