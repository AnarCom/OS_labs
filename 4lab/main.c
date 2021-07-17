#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	char buf[BUFSIZ] = {0};
	Node * head = createNode();
	if(head == NULL){
		perror("failed to allocate memory");
		return -3;
	}
	Node *now = head;
	while(
		fgets(buf, BUFSIZ,stdin) != NULL
		&& buf[0] != '.') {
		now->next = fillNode(buf);
		if(now->next == NULL){
			perror("failed to allocate memory");
			freeList(head);
			return -3;
		}
		now = now -> next;
	}	
	printList(head);
	freeList(head);
	return 0;
}
