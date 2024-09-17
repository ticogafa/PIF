//Primeira questão:

//A) Sim, uma vez que o valor dentro do endereço armazenado pelo ponteiro p foi alterado ao longo do código. 
//Antes do primeiro print, p guardava o endereço da variável a, como representado pela linha int *p = &a. 
//Desta forma, o primeiro print exibe o valor da variável a naquele momento, ou seja 5. 

//Logo antes do quarto print, contudo, o ponteiro p recebe o valor da variável b e o atualiza no endereço 
//da variável a. Ou seja, a se torna 14 agora. Quando formos imprimir *p, ou seja, o valor de a, 
//teremos agora o valor 14 sendo exibido na tela.
//Este código é um exemplo do uso de ponteiro para atualizar o valor de variáveis de maneira indireta.


//B) Podemos imprimir o elemento de arrays através do uso dos indices ou através da aritmética de ponteiros. Por exemplo, teríamos:
//                          printf(“%d “, c[2]);
//                         printf(“%d”, *(c + 2)); => o próprio c é um array
//                        printf(“%d”, *(arr + 2)); => arr aponta para o array c

//Segunda questão:

int converte(char *array){

	int i, n = 8, res = 0, count = 0;
	
	for(i = 0; i< n; i++){
		if(array[i] == '1'){
			res = res + (pow(2,(n-1)-i)); //bit mais significativo no começo
        }
	}
  
   	return res;

}
