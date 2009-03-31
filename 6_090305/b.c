#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	pid_t pid1, pid2, pid3, pid4;
	int i;
	pid1 = fork();
	if(pid1 == 0) {
		pid2 = fork(); 
		if(pid2 == 0) {
			pid3 = fork();
			if(pid3 == 0) {
				pid4 = fork();
				if(pid4 == 0) {
					printf("A\n");
					sleep(1);
					wait(NULL);
					printf("a child %d has terminated.\n",getpid());
					exit(0);
				}
				for(i=0;i<2;i++) {
					printf("B");
					sleep(1);
				}
				printf("\n");
				wait(NULL);
				printf("a child %d has terminated.\n",getpid());
				exit(0);
			}
			for(i=0;i<3;i++) {
				printf("C");
				sleep(1);
			}
			printf("\n");
			wait(NULL);
			printf("a child %d has terminated.\n",getpid());
			exit(0);
		}
		for(i=0;i<4;i++) {
			printf("D");
			sleep(1);
		}
		printf("\n");
		wait(NULL);
		printf("a child %d has terminated.\n",getpid());
		exit(0);
	}
	wait(NULL);
	printf("Parent process has terminated.\n");
	return 0;
}
