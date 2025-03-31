//(STRINGS - 1.5 pontos) Desenvolva uma função chamada only_alpha_num() capaz de extrair de uma string qualquer 
//caractere que não seja alfanumérico (que não seja letras de a à z minúsculas e maiúsculas e dígitos de 0 a 9). 
//Por exemplo, se você receber a frase “B@m dia gente!”, sua função deve gerar a string “Bmdiagente”. Sua função 
//deve receber dois ponteiros para char, o primeiro representa a string de origem str1 e o segundo a string a ser convertida str2. 
//Ambas as strings terão tamanho máximo de 100 caracteres (incluindo o ‘\0’). Sua função deve ter tipo de retorno  void. 

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
