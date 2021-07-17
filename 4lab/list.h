typedef struct Node {
	char * data;
	struct Node * next;
} Node;

void addNode(Node * node);
Node * createNode(char * string);
void addToNodeList(Node * node, char string);
void deleteNode(Node * nodes);
void deleteNodes(Node * nodes);
