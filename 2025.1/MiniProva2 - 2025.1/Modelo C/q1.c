//QUESTÃO 01 (STRINGS - Maior e Menor nome - 1.5 pontos) Implemente um programa capaz de receber uma lista de nomes de alunos e  
//indicar o maior e menor nome em termos do número de letras. Seu programa deve:
//A)Receber a listagem de nomes até que o usuário digite a palavra “FIM”. Os nomes inserido são compostos de nome e sobrenome; (0.5 pontos)
//B)Calcular o tamanho de cada nome. Por tamanho, aqui consideramos o tamanho completo, considerando tanto nome quanto sobrenome (0.75 pontos)
//C)Imprimir o maior e menor nome no seguinte formato: (0.25 pontos)
//“Maior nome é : X e contém L letras”
//“Menor nome é : Y e contém Q letras”
//
//Por exemplo, se temos a listagem abaixo:
//	Tiago Barros
//	Pamela Bezerra
//	Everton Tadeu
//	Gabrielle Canalle
//	FIM
//O resultado esperado é:
//	“Maior nome é: Gabrielle Canalle e contém 16 letras”
//	“Menor nome é: Tiago Barros e contém 11 letras
//
//OBS - Caso haja dois ou mais nomes com o mesmo número de letras (número máximo ou mínimo), imprima o número que vem primeiro na ordem alfabética.
//
#include <stdio.h>

#define MAX_NOMES 100
#define MAX_TAMANHO 100

int main() {
    char nomes[MAX_NOMES][MAX_TAMANHO];
    char maiorNome[MAX_TAMANHO], menorNome[MAX_TAMANHO];
    int qtdNomes = 0;
    int tamMaior = 0, tamMenor = 1000;

    printf("Digite os nomes (digite 'FIM' para encerrar):\n");
    
    while (1) {
        char nome[MAX_TAMANHO];
        fgets(nome, MAX_TAMANHO, stdin);
        nome[strcspn(nome, "\n")] = 0; // Remove o \n do final
        
        if (strcmp(nome, "FIM") == 0) break;
        
        strcpy(nomes[qtdNomes], nome);
        qtdNomes++;
    }
    
    for (int i = 0; i < qtdNomes; i++) {
        int tamanho = strlen(nomes[i]);
        
        if (tamanho > tamMaior || (tamanho == tamMaior && strcmp(nomes[i], maiorNome) < 0)) {
            tamMaior = tamanho;
            strcpy(maiorNome, nomes[i]);
        }
        
        if (tamanho < tamMenor || (tamanho == tamMenor && strcmp(nomes[i], menorNome) < 0)) {
            tamMenor = tamanho;
            strcpy(menorNome, nomes[i]);
        }
    }
    
    printf("Maior nome é: %s e contém %d letras\n", maiorNome, tamMaior);
    printf("Menor nome é: %s e contém %d letras\n", menorNome, tamMenor);
    
    return 0;
}