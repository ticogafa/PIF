//Você ficou encarregado (a) de fazer a parte de controle das informações dos alunos da disciplina de PIF. 
//Cada aluno possui um nome (no máximo 50 caracteres), quantidade de faltas (inteiro), array com 10 notas representando 
//as listas de exercício e mini provas  (float) e a média geral do aluno (float). Implemente o seguinte:

//Estrutura do aluno com base nos dados descritos na questão (0.5);
//Função de inserção de alunos em ordem alfabética de nome (1.0);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct aluno{ //dados do aluno
    
    char nome[51];
    int faltas;
    float notas[10];
    float media;
    struct aluno *next;
};

void inserir_alunos(struct aluno **head, char nome[51], int faltas, float notas[10], float media){ 
  struct aluno *n = *head; //ponteiro auxiliar
  
  struct aluno *novo = (struct aluno *) malloc(sizeof(struct aluno)); //construindo o novo nó da lista
  strcpy(novo->nome, nome); //strings necessitam de strcpy
  novo->faltas = faltas;
  novo->media = media;
  
  for(int i=0; i<10; i++){
      novo->notas[i] = notas[i];
  }
  
  if(*head == NULL){ //lista vazia
     *head = novo;
     novo->next = NULL;
     
  }else{
      
    if (strcmp((*head)->nome, nome) > 0){ //novo nome vem antes do primeiro elemento da lista
        
        novo->next = *head;
        *head = novo; //inserção no começo da lista
    }else{
        
        while(n->next != NULL && strcmp(n->next->nome,nome) < 0){ //percorrer enquanto os nós forem menores que o nome
            n = n->next;
        }
        
          novo->next = n->next; //inserção no meio ou final
          n->next = novo;
         
    }
    
   }
}

void imprimir_lista(struct aluno *head) {
    struct aluno *n = head;
   
    while (n!=NULL) {
        printf ("%s %d %f\n", n->nome, n->faltas, n->media);
        n = n->next;
    }
}

int main()
{
    struct aluno *head = NULL;
    char nome[51] = "Coraline";
    int faltas = 7;
    float notas[10]= {1, 1.5, 2, 0.5, 1, 1.25, 2.5, 3, 1, 1.5};
    float media = 7.0;
    
    inserir_alunos(&head, nome, faltas, notas, media);
    
    strcpy(nome,"Aline");
    faltas = 0;
    media = 9.5;
    
    for(int i = 0; i<10; i++){
        if(i%2 == 0){
            notas[i] = notas[i] + 0.5;
        }else{
            notas[i] = notas[i] - 0.5;
        }
    }
    
    inserir_alunos(&head, nome, faltas, notas, media);
    
    imprimir_lista(head);

    return 0;
}
