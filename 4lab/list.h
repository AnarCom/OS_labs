#ifndef INC_4LAB_LIST_H
#define INC_4LAB_LIST_H
typedef struct Node {
    char * data;
    struct Node * next;
} Node;

Node *addNode(Node *node, char *str);

void deleteNodes(Node *head);

void printNodes(Node *head);
#endif //INC_4LAB_LIST_H
