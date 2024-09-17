//Primeira questão:

int operacaoArray(int arr[], int N, char C) {
    int resultado;
    
    if (C == 'S') {
        resultado = 0;
        for (int i = 0; i < N; i++) {
            resultado += arr[i];
        }
    } else if (C == 'P') {
        resultado = 1;
        for (int i = 0; i < N; i++) {
            resultado *= arr[i];
        }
    } else {
        return -1;
    }
    
    return resultado;
}

//Segunda questão:

//A) Os valores impressos são, nesta ordem, num2 e num1, uma vez que dentro da função a troca 
//ocorreu corretamente, ou seja, num1 recebeu o valor de num2 e vice versa.

//B) Dentro da main, os valores impressos para num1 e num2 são os mesmo pssados pelo usuário pois 
//a troca entre valores não foi realizada. Isso ocorre pois a função swap() faz uso de passagem por
// valor ao invés de referência, o que imposibilita que os valores sejam devidamente atualizados fora do escopo da função.

//C)Para que a passagem por referência seja feita de maneira correta, precisamos passar o endereço das variáveis, 
//e não seus valores. Para isso, precisamos ter ponteiros como parâmetro da função:

//void swap(int *num1, int *num2)

// Além disso, dentro da função, precisamos usar esta ponteiros para atualizar corretamente os valores das variáveis, o que é feito pelo código abaixo:
//temp = *num1;
//*num1 = *num2;
//*num2 = temp;
//Com isso, conseguiremos atualizar corretamente os valores das variáveis.