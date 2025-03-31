//(STRINGS - 1.5 pontos) Implemente a função new_length() a qual determina o tamanho de uma string de uma maneira bem diferente: 
//ela retorna a soma dos caracteres alfabéticos (a à z; e A à Z) contidos na string  ao invés do número de caracteres 
//(ou seja, ela retorna a soma dos valores da tabela ASCII destes caracteres). A função deve receber um ponteiro para char (string) 
//e retornar um número inteiro. Considere que a string pode ser formada por qualquer caractere da tabela ASCII, entretanto você só 
//vai considerar na soma os caracteres alfabéticos. 

int new_length(char *str1){
    
    int soma = 0;
    
    for(int i = 0; str1[i] != '\0'; i++){
        
          if((str1[i] >= 'a' && str1[i] <= 'z' ) || (str1[i] >= 'A' && str1[i] <= 'Z')){
              
              soma = soma + str1[i]; 
          }
    }
    
    return soma;

}

