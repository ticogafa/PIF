float area(float *array, char op){
	float resultado;
	
	//verificando se os dois valores são válidos
	if(array[0] >= 0 && array[1] >= 0){
		if(op == 'R' || op == 'Q'){
			resultado = array[0]*array[1];
		}else if(op == 'L'){
			resultado = (array[0]*array[1])/2;
		}else{
			printf("Opção errada!\n");
			return 0;
		} 
	}
	else{
		printf("Opção errada!\n");
		return 0;
	}

	return resultado; 
}


//Segunda questão:

//A) Dado que prt1 e prt2 são dois ponteiros armazenando os endereços de memória das variáveis fno e sno, respectivamente, 
//e que o uso do símbolo *em um ponteiro significa que estamos capturando o valor dentro do endereço armazenado pelo mesmo, 
//*ptr1 > *ptr2 é a mesma coisa de fno > sno.Ou seja, estamos usando os ponteiros para acessar indiretamente as variáveis e 
//realizar comparações entre elas.

//                                                                                                                                                                                                                                                                                                     Sim,
//B) Sim, o código funcionaria uma vez que, dado que prt1 é um ponteiro que guarda o endereço da variável fno e o operador 
//&significa que estamos capturando o endereço de uma dada variável, prt1 e &fno, significam a mesma coisa, o endereço da variável fno.

//                                                                                                                                                                                                                                    Reposta alternativa -
//                                                                                                                                                                                                                                    Sim,
//Alternativa: Sim, pois a função scanf necessita do endereço de um variável para atualizar seu valor corretamente com a informação
// do usuário.Neste contexto, tanto ptr1 quanto &fno correspondem ao endereço da variável fno, uma vez que prt1 aponta para fno.
//

//C) Ao trocar o identificador de variáveis de % d para % p, além de remover o operador *de perto do ponteiro ptr1, passamos agora a 
//imprimir o endereço de memória armazenado em ptr1, ou seja, o endereço da variável fno, ao invés do valor de fno.

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                              Reposta alternativa -
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                              o primeiro print exibe o valor contido na variável fno,
//Alternativa: primeiro print exibe o valor contido na variável fno, pois usamos o identificador de variáveis inteiras % d e aplicamos
// o operador *ao ponteiro prt1, o qual guarda o valor da variável fno.Já o segundo print imprime o endereço de fno, já que estamos
// usando o identificar de ponteiro % p e não aplicamos o operador *ao ptr1.
