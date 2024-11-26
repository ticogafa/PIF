//Todo ano, o Spotify cria uma lista personalizada para cada usuário com base nas músicas mais ouvidas naquele ano. 
//O aplicativo constrói esta lista com base no tempo total gasto ouvindo cada música. 
//Suponha a seguinte estrutura autoreferenciada com os dados da música:
//
//struct musica{
//		char nome[50];
//		char artista[100];
//		char album[50];
//		int minutos;
//		struct musica *next;
//};
//
//Onde a variável minutos representa o tempo total que o usuário ouviu determinada música 
//(ou seja, a soma do tempo de todas as execuções da música). Esta lista está ordenada por ordem alfabética do nome do 
//artista e não há nomes duplicados de músicas. Implemente o seguinte: 
//
//Função para encontrar a  música mais ouvida no ano. Sua função deve imprimir o nome da música, artista, e álbum (0.5);
//Função para encontrar  o tamanho total da lista (ou seja, quantas músicas diferentes o usuário ouviu naquele ano) (0.5);
//Função para encontrar o tempo total que usuário passou no aplicativo ouvindo músicas (0.5);
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct musica{
	char nome[50];
	char artista[100];
	char album[50];
	int minutos;
	struct musica *next;
};

void mais_ouvida(struct musica *head){ // Descobrir a musica mais tocada
    int max = 0;
    char musica[50];
    char art[100];
    char disco[50];
    
    struct musica *aux = head; //ponteiro auxiliar
    
    if(head == NULL){
        printf("Lista vazia\n");
    }else{
         
        while(aux != NULL){
            if(aux->minutos >= max){
                max = aux-> minutos;
                strcpy(musica,aux->nome);
                strcpy(art,aux->artista);
                strcpy(disco,aux->album);
            }
            
            aux = aux->next;
        }
    
     printf("Música mais tocada foi: %s de %s do album %s\n", musica, art, disco);
    
    }
}

int tamanho(struct musica *head){ // contar a quantidade de músicas
    int count = 0;
    struct musica *aux = head; //ponteiro auxiliar
    
    if(head == NULL){
        return 0;
    }else{
         
        while(aux != NULL){
            aux = aux->next;
            count++;
        }
    
    return count;
    
    }
}

int tempo_total(struct musica *head){ // tempo total ouvindo música
    int soma = 0;
    struct musica *aux = head; //ponteiro auxiliar
    
    if(head == NULL){
        return 0;
    }else{
         
        while(aux != NULL){
            soma = soma + aux->minutos;
            aux = aux->next;
    
        }
    
    return soma;
    
    }
}


void inserir_musica(struct musica **head, char art[100], char musica[100], char album[50], int min){ 
  struct musica *n = *head; //ponteiro auxiliar
  
  struct musica *novo = (struct musica *) malloc(sizeof(struct musica)); //construindo o novo nó da lista
  strcpy(novo->nome, musica); 
  strcpy(novo->artista, art);
  strcpy(novo->album, album);
  novo->minutos = min;
  
  if(*head == NULL){ //lista vazia
     *head = novo;
     novo->next = NULL;
     
  }else{
      
    if (strcmp((*head)->artista, art) > 0){ //novo nome vem antes do primeiro elemento da lista
        
        novo->next = *head;
        *head = novo; //inserção no começo da lista
    }else{
        
        while(n->next != NULL && strcmp(n->next->artista,art) < 0){ //percorrer enquanto os nós forem menores que o nome
            n = n->next;
        }
        
          novo->next = n->next; //inserção no meio ou final
          n->next = novo;
    }
    
   }
}

void imprimir_lista(struct musica *head) {
    struct musica *n = head;
   
    while (n!=NULL) {
        printf ("[%s por %s: %d minutos] ", n->nome, n->artista, n->minutos);
        n = n->next;
    }
    
    printf("-> NULL\n");
}

int main()
{
    struct musica *head = NULL;
    printf("===== TESTE LISTA VAZIA ===== \n");
    printf("total de músicas: %d, total de tempo: %d\n", tamanho(head), tempo_total(head));
    
    mais_ouvida(head);
    
    
    printf("\n ===== PRIMEIRO BATCH DE MUSICAS ===== \n");
    inserir_musica(&head,"Adele", "Set Fire to the Rain", "21", 16);
    inserir_musica(&head,"Lana Del Rey", "Cherry", "Lust for Life", 30);
    inserir_musica(&head,"Bishop Briggs", "River", "Church of Scars", 18);
    
    imprimir_lista(head);
    printf("total de músicas: %d, total de tempo: %d\n", tamanho(head), tempo_total(head));
    mais_ouvida(head);
    
    
    printf("\n ===== SEGUNDO BATCH DE MUSICAS ===== \n");
    inserir_musica(&head,"Mabel", "Finders Keepers", "Ivy to Roses", 40);
    inserir_musica(&head,"Charli xcx", "360", "Brat", 8);
    inserir_musica(&head,"Rihana", "Needed Me", "ANTI", 36);
    inserir_musica(&head,"HWASA", "Maria", "Maria", 60);
    
    imprimir_lista(head);
    printf("total de músicas: %d, total de tempo: %d\n", tamanho(head), tempo_total(head));
    mais_ouvida(head);
    

    return 0;
}