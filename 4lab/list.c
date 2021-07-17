#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

Node * fillNode(Node * node, char * string) {
	node -> data = (char *) calloc(strlen(string) + 1, sizeof(char));
	if(node -> data == NULL){
		perror("cannot create node -> data (calloc)");
		return NULL;
	}
	memcpy(node -> data, string, strlen(string) * sizeof(char));
	return node;
}

Node * createNote(char * string) {
	Node * node = malloc(sizeof(Node));
	if(node == NULL){
		perror("cannot alloc node (malloc(3C))");
		return NULL;
	}
	node -> next = NULL;
	node = fillNode(node, string);
	return node;
}

void deleteNode (Node * node){
	free(node -> data);
	free(node);
}
