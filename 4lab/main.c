#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    char buf[BUFSIZ] = {0};
    Node *node = NULL;
    while (
            fgets(buf, BUFSIZ, stdin) != NULL
            && buf[0] != '.') {
        node = addNode(node, buf);
    }
    printNodes(node);
    deleteNodes(node);
    return 0;
}
