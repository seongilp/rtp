#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int i = 0;
	int j;
	char c = 'A';
	while(i<4) {
		i++;
		pid = fork();
		if(pid==0) {
			for(j=0;j<i;j++) {
				printf("%c",c);
				fflush(stdout);
				sleep(1);
			}
			printf("\n");
			exit(0);
		}
		c++;
	}
	for(i=0;i<4;i++) {
		wait(NULL);
		printf("a child %d has terminiated.\n",pid);
	}
	printf("Parent process has terminated.\n");
	return 0;
}
