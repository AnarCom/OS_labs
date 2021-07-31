#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <ulimit.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

extern char **environ;


int main(int argc, char ** argv){
	int currentArg;
	char options [] = "ispuU:cC:dvV:";
	while((currentArg = getopt(argc, argv, options)) != EOF){
		switch(currentArg){
			case 'i': {
				printf("Real id USER: %d\n", getuid());
				printf("Effective id USER: %d\n", geteuid());
				printf("Read id GROUP:%d\n", getuid());
				printf("Effective id GROUP:%d\n", getegid());
				break;
			}
			case 's': {
				if(setpgid(0, 0) != 0){
					perror("Failed to set new process id");
				}
				break;
			}
			case 'p': {
				printf("Process ID: %d\n", getpid());
				printf("Parent ID: %d \n", getppid());
				printf("Group id: %d \n", getpgid(0));
				break;
			}
			case 'u': {
				printf("Soft file size of this process: %ld\n", ulimit(UL_GETFSIZE));
				break;
			}
			case 'U': {
				if(ulimit(UL_SETFSIZE, atol(optarg)) != atol(optarg)){
					perror("Only process with appropriate privileges can INCREASE their limit (any process can DECREASE)\n");
				}
				break;
			}
			case 'c': {
				struct rlimit cFileLimit;
				getrlimit(RLIMIT_CORE, &cFileLimit);
				printf("Soft core file limit: %lu bytes\n", cFileLimit.rlim_cur);
				printf("Hard core file limit: %lu bytes\n", cFileLimit.rlim_max);
				break;
			}
			case 'C': {
				struct rlimit cFileLimit;
				int optArgInt = atoi(optarg);
				cFileLimit.rlim_cur = optArgInt;
				cFileLimit.rlim_max = optArgInt;
				if(setrlimit(RLIMIT_CORE, &cFileLimit) != 0){
					perror("Only process with appropriate priveleges can INCREASE their limit (any process can DECREASE)\n");
				}
				break;
			}
			case 'd': {
				char *buffer = get_current_dir_name();
				printf("Current directory is: %s\n", buffer);
				break;
			}
			case 'v': {
				char ** en;
				for(en = environ; *en; en++){
					printf("%s\n", *en);
				}
				break;
			}
			case 'V': {
				int count = 0;
				for(count=0; optarg[count]=='=';optarg++);
				char *envName = malloc(sizeof(char) * (count + 1));
				char *envValue = malloc(sizeof(char) * (strlen(optarg) - count));
				if(envName == NULL || envValue == NULL){
					perror("Cannot allocate memoty\n");
					free(envName);
					free(envValue);
				}
				strncpy(envName, optarg, count);
				strcpy(envValue, optarg + count + 1);
				if(setenv(envName, envValue, 1) != 0){
					perror("Failed to set new env var\n");
				}
				free(envName);
				free(envValue);
				break;
			}
			default:
				perror("No such option\n");
		}
	}
return 0;
}

