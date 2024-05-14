#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct Node{
    char name[MAX_NAME_LENGTH];
    struct Node *next;
} Node;

Node *createNode(char *name){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node **head, char *name){
    Node *newNode = createNode(name);
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

void insertBefore(Node **head, Node *newList, char *target){
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
    printf("\n");
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
    char input[MAX_NAME_LENGTH];
    char target[MAX_NAME_LENGTH];

    fgets(input, MAX_NAME_LENGTH, stdin);
    char *token = strtok(input, " ");
    while (token != NULL){
    char *name = strdup(token);  // Create a copy of the token
    insertNode(&friendsList, name);
    token = strtok(NULL, " ");
}

    fgets(input, MAX_NAME_LENGTH, stdin);
    token = strtok(input, " ");
    while (token != NULL){
    char *name = strdup(token);  // Create a copy of the token
    insertNode(&newList, name);
    token = strtok(NULL, " ");
}

    fgets(target, MAX_NAME_LENGTH, stdin);
    target[strcspn(target, "\n")] = '\0';

    if (strcmp(target, "nao") != 0){
    insertBefore(&friendsList, newList, target);
}
    else{
    Node *current = newList;
    while (current != NULL){
        insertNode(&friendsList, current->name);
        current = current->next;
    }
}

printList(friendsList);

freeList(friendsList);
freeList(newList);

    return 0;
}