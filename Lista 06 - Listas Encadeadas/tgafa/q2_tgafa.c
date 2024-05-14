#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char name[50];
    struct Node *next;
} Node;

Node *criarnome(char *name){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void inserir(Node **head, char *name){
    Node *newNode = criarnome(name);
    if (*head == NULL){
        *head = newNode;
    }
    else{
        Node *current = *head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void inserirAntes(Node **head, Node *newList, char *target){
    if (*head == NULL || newList == NULL){
        return;
    }

    Node *current = *head;
    Node *prev = NULL;

    while (current != NULL && strcmp(current->name, target) != 0){
        prev = current;
        current = current->next;
    }

    if (current == NULL){
        return;
    }

    if (prev == NULL){
        Node *lastNode = newList;
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = *head;
        *head = newList;
    }
    else{
        Node *lastNode = newList;
        while (lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        lastNode->next = current;
        prev->next = newList;
    }
}

void printList(Node *head){
    Node *current = head;
    while (current != NULL){
        printf("%s ", current->name);
        current = current->next;
}
}

void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(){
    Node *friendsList = NULL;
    Node *newList = NULL;
    char input[50];
    char target[50];

    fgets(input, 50, stdin);
    char *token = strtok(input, " ");
    while (token != NULL){
    char *name = strdup(token); 
    inserir(&friendsList, name);
    token = strtok(NULL, " ");
}

    fgets(input, 50, stdin);
    token = strtok(input, " ");
    while (token != NULL){
    char *name = strdup(token);  
    inserir(&newList, name);
    token = strtok(NULL, " ");
}

    fgets(target, 50, stdin);
    target[strcspn(target, "\n")] = '\0';

    if (strcmp(target, "nao") != 0){
    inserirAntes(&friendsList, newList, target);
}
    else{
    Node *current = newList;
    while (current != NULL){
        inserir(&friendsList, current->name);
        current = current->next;
    }
}

printList(friendsList);

freeList(friendsList);
freeList(newList);

    return 0;
}