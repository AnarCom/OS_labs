#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char ** argv){
	if(argc <= 1){
		perror("No filename\n");
		return -1;
	}
	struct flock lock;
	int fd = open(argv[1], O_RDWR);
	if(fd == -1){
		perror("Could not open file:");
		perror(argv[1]);
		perror("\n");
		return -1;
	}
	printf("File was opened\n");
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	if(fcntl(fd, F_SETLK, &lock) == -1){
		perror("Error in fcntl\n");
		return -1;
	}

	char *command = malloc(sizeof(char) * (FILENAME_MAX + strlen("nano ")));
	if(command == NULL){
		perror("Cannot allocate memory for command\n");
		return -1;
	}
	sprintf(command, "nano %s", argv[1]);
	system(command);
	free(command);

	lock.l_type = F_UNLCK;
	if(fcntl(fd, F_SETLK, &lock) == -1){
		perror("Failed to unlock file\n");
		return -1;
	}

	close(fd);
	return 0;

}
