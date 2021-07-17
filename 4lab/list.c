#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>

void freeNode(Node* node){
    node->next = NULL;
    free(node->data);
    free(node);
}

Node* createNode(){
    Node* node = (Node*)malloc(1 * sizeof(Node));
    if (node == NULL){
        perror("malloc failed to allocate a new node\n");
        return NULL;
    }
    node->next = NULL;
    node->data = NULL;
    return node;
}

Node* fillNode(char* line){
    Node* node = createNode();

    node->data = (char*)calloc((strlen(line) + 1), sizeof(char));
    if (node->data == NULL){
        free(node);
        return NULL;
    }

    memcpy(node->data, line, (strlen(line) + 1) * sizeof(char));

    node->next = NULL;
    return node;
}

void freeList(Node* head){
    if (head == NULL){
        return;
    }

    Node* next = head->next;
    Node* savedNode = NULL;
    while (next != NULL){
        savedNode = nextNode->nextNode;
        freeNode(nextNode);
        next = savedNode;
    }
    freeNode(head);
}

void printList(Node* head){
    Node* node;
    for (node = head->next; node != NULL; node = node->next){
        printf("%s", node->data);
    }
}
