//Você ficou encarregado(a) de implementar a lista de jogadores no projeto de PIF da segunda unidade. 
//No projeto de seu grupo, cada jogador é composto por apelido (char de no máximo 4 caracteres), 
//quantidade de pontos (inteiro) e o tempo (em segundos) total que o jogador levou para terminar o jogo (inteiro). 
//Sua lista deve ordenar os jogadores de maneira (1) decrescente em termos dos pontos (do maior para o menor) e 
//(2) crescente em termos do tempo (do mais rápido ao mais devagar). Por exemplo, se temos dois jogadores, kaka e 
//dino, ambos com mesma pontuação, contudo kaka terminou a fase em 300 segundos (ou seja, 5 min) e dino terminou em 
//240 segundos, o nome de dino vem antes do de kaka na lista. Implemente:


//Estrutura do jogador com base nos dados descritos na questão (0.5);
//Função de inserção de jogadores de maneira ordenada em termos de pontos e tempo (1.0);
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogador{ //dados do jogador
    
    char apelido[5];
    int pontos;
    int tempo;
    struct jogador *next;
};


//Critérios - A questão é bem direta, ou o estudante sabe fazer uma struct ou não sabe. Caso simples de erro de 
//sintaxe ou faltou algum atributo, podemos reduzir 0.1, contudo erros mais graves de entendimento da questão ou 
//do que são structs levam a zerar a questão. Mais detalhes abaixo:

//Se o aluno descreveu a struct correta, usando typedef ou não = considerar tudo;
//Se o aluno não considerou o ponteiro para o próximo elemento (estrutura autoreferenciada) = reduzir 0.3;
//Se o estudante esqueceu algum dos atributos da struct = reduzir 0.1
//Se o estudante ainda não sabe como definir uma struct = zerar a questão 
//

void inserir_jogador(struct jogador **head, char *apelido, 
                     int pontos, int tempo) {

    struct jogador *tmp = *head, *novo = (struct jogador*) 
                           malloc(sizeof(struct jogador));

    strncmp(novo->apelido, apelido, 4);
    novo->pontos = pontos;
    novo->tempo = tempo;
    novo->next = NULL;

    if (*head == NULL) { //lista vazia
        *head = novo;
    } else {
        // inserção no primeiro elemento
        if (tmp->pontos < pontos || 
            (tmp->pontos==pontos && tmp->tempo > tempo)) {
            novo->next = *head;
            *head = novo;
        } else { // caso geral

            while(tmp->next != NULL 
                  && tmp->next->pontos > pontos) {
                tmp = tmp->next;
            }
            while (tmp->next!=NULL && tmp->next->pontos==pontos            
                   && tmp->next->tempo < tempo) {
                tmp = tmp->next;
            }
            novo->next = tmp->next;
            tmp->next = novo;
        }
    }
}


//Critérios = o mais importante da questão é o estudante saber implementar os mecanismos necessários 
//para inserir os elementos de maneira ordenada. Os demais componentes são auxiliares. Mais uma vez, aqui 
//deve-se entender a gravidade do erro, se foi um erro simples de sintaxe, algum detalhe que faltou, ou um 
//erro de entendimento completo do processo de inserir em listas encadeadas.

//Não foi feita a criação do novo nó (ou seja, alocação dinâmica e atribuição dos valores passados como parâmetro)  
//ou a criação está parcialmente correta = reduzir 0.1 a 0.2 dependendo do erro

//Não foi tratado o caso em que o novo nó deve ser inserido no começo da lista = reduzir 0.3

//A lógica de percorrer a lista e adicionar o nó na posição correta (meio ou fim) está errada 
//ou parcialmente errada = reduzir de 0.1 a 0.4 dependendo do erro.

//Não foi tratado o caso de lista vazia = reduzir 0.1
//
