#include <stdio.h>
#include <stdlib.h>
  
struct aluno {
        char nome[50];
        char sobrenome[50];
        float media;
        int faltas;
    };
  

int main(){

    int num_alunos;
    struct aluno *alunos;


    scanf("%d", &num_alunos);
    alunos = (struct aluno*)malloc(num_alunos * sizeof(struct aluno));


    for (int i = 0; i < num_alunos; i++) {
        printf("Nome: ");
        scanf("%s", alunos[i].nome);


        printf("Sobrenome: ");
        scanf("%s", alunos[i].sobrenome);


        printf("Media: ");
        scanf("%f", &alunos[i].media);


        printf("Faltas: ");
        scanf("%d", &alunos[i].faltas);
    }


    float sun_notas = 0;
    int quant_repovados_faltas = 0;


    for (int i = 0; i < num_alunos; i++) {
        sun_notas += alunos[i].media;


        if (alunos[i].faltas >= 15) {
            quant_repovados_faltas++;
        }
    }


    float media = sun_notas / num_alunos;
    printf("A media da sala foi %f, e a quantidade de alunos reporvados por falta foi %d", media, quant_repovados_faltas);

    free(alunos);

}

/*

(STRUTCS E ALOCAÇÃO DINÂMICA DE MEMÓRIA - 2.0 pontos) Escreva um programa para cadastro de alunos 
em uma disciplina, definindo uma estrutura chamada aluno com as seguintes informações: nome (string 
tamanho 50), sobrenome (string tam 50), media (float) e faltas (int). Seu programa deve receber o 
número de alunos matriculados na disciplina e alocar dinamicamente um vetor da estrutura aluno com 
este tamanho. Depois deve receber as informações do usuário para cada aluno cadastrado e, ao final, 
imprimir (1) a média das notas da turma e (2) a quantidade de alunos reprovados por falta (lembrando 
que um número de faltas igual ou maior que 15 reprova o aluno). Ao final de tudo, seu programa deve 
desalocar a memória alocada dinamicamente.

a)Estrutura aluno (0.3 pontos)
b)Alocação dinâmica do array (0.7 pontos)
c)Receber dados o usuário, cálculo da média e impressões  (0.8 pontos)
d)Desalocar memória (0.2 pontos)


*/