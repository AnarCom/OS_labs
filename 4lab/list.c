#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

Node * fillNode(Node * node, char * string) {
	node -> data = (char *) calloc(strlen(string) + 1, sizeof(char));
	if(node -> data == NULL){
		perror("cannoß≈
