#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEXTIME_LEN 6

char* get_hextime(int is_capped) 
{
	char *hextime;
	hextime = malloc(HEXTIME_LEN);
	time_t rawtime;
	
	rawtime = time(NULL);
	struct tm *timeinfo = localtime(&rawtime);

	if(is_capped)
		sprintf(hextime, "%X:%X:%X\n", timeinfo->tm_hour, timeinfo->tm_min, 
				timeinfo->tm_sec);
	else
		sprintf(hextime, "%x:%x:%x\n", timeinfo->tm_hour, timeinfo->tm_min, 
				timeinfo->tm_sec);
	return hextime;
}

int main(int argc, char *argv[])
{
	char c;
	int uppercase = 0;
	while((c = getopt(argc, argv, "hu")) != -1)
		switch(c)
		{
			case 'h':
				printf("u: uppercase, h: this message");
				exit(0);
			case 'u':
				uppercase = 1;
				break;
			case '?':
				printf("u: uppercase, h: this message");
				exit(1);
			default:
				abort();
		}
	printf("%s\n", get_hextime(uppercase));
	return 0;
}
