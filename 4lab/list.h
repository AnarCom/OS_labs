typedef struct Node {
	char * data;
	struct Node * next;
} Node;

void freeNode(Node* node);
Node* createNode();
Node* fillNode(char* line);
void freeList(Node* head);
void printList(Node* head);