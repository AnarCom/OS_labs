#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>

extern char *tzone[];

int main(){
	time_t now;
	struct tm *sp;
	putenv("TZ=America/Los_Angeles");
	if(time( &now ) == -1){
		printf("broken");
		exit(-1);
	}
	sp = localtime( &now );
	printf("date: %d/%d/%02d\n", 
		sp -> tm_mon + 1,
		sp -> tm_mday,
		sp -> tm_year);

	printf("time: %d:%d:%d\n",
		sp -> tm_hour,
		sp -> tm_min);

	printf("time zone: %s\n",
		tzname[sp -> tm_isdst]);
	return 0;
}
