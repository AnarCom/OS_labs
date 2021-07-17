#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	char buf[BUFSIZ] = {0};

	while(
		fgets(buf, BUFSIZ,stdin) != NULL
		&& buf[0] != '.') {
		
		printf("%s\n", buf);
	}	
	return 0;
}
