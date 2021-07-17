#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Node *createNode(char *str) {
    Node *node = malloc(1 * sizeof(Node));
    if (node == NULL) {
        perror("cannot allocate memory");
        return NULL;
    }
    node->next = NULL;
    node->data = calloc(strlen(str) + 1, sizeof(char));
    if (node->data == NULL) {
        perror("cannot allocate memory for string");
    }
    memcpy(node->data, str, (strlen(str) + 1) * sizeof(char));
    return node;
}

Node *addNode(Node *node, char *str) {
    if (node == NULL) {
        return createNode(str);
    } else {
        Node * now = node;
        while (now -> next != NULL)
            now = now->next;
        now->next = createNode(str);
        return node;
    }
}


void deleteNodes(Node *head){
    while (head != NULL){
        Node * buf = head->next;
        free(head);
        head = buf;
    }
}

void printNodes(Node *head){
    while (head != NULL){
        printf("%s", head->data);
        head = head->next;
    }
}