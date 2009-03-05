#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define DEBUG 0

int main(void)
{
	pid_t pid0, pid1, pid2, pid3, pid4;
	int i = 0;
	pid0 = fork();
	if(pid0 > 0) {
		pid1 = fork();
		if(pid1 == 0)

		if(DEBUG) 
			printf("Parent pid is %d.\n",getpid());
		wait(NULL);
		printf("parent process has terminated.\n",getpid());	
		exit(0);
	}
	pid1 = fork();
	if(pid1 > 0) {
		if(DEBUG) 
			printf("pid of p1 is %d.\n",getpid());	
		printf("A\n");
		sleep(1);
		wait(NULL);
		printf("A child %d has terminated.\n",getpid());	
		exit(0);
	}
	pid2 = fork();
	if(pid2 > 0) {
		if(DEBUG) 
			printf("pid of p2 is %d.\n",getpid());	
		for(i=0;i<2;i++) {
			printf("B");
			sleep(1);
		}
		printf("\n");
		wait(NULL);
		printf("A child %d has terminated.\n",getpid());	
		exit(0);
	}
	pid3 = fork();
	if(pid3 > 0) {
		if(DEBUG) 
			printf("pid of p3 is %d.\n",getpid());	
		for(i=0;i<3;i++) {
			printf("C");
			sleep(1);
		}
		printf("\n");
		printf("A child %d has terminated.\n",getpid());	
		wait(NULL);
		exit(0);
	}
	pid4 = fork();
	if(pid4 > 0) {
		if(DEBUG) 
			printf("pid of p4 is %d.\n",getpid());	
		for(i=0;i<4;i++) {
			printf("D");
			sleep(1);
		}
		printf("\n");
		printf("A child %d has terminated.\n",getpid());	
		wait(NULL);
		exit(0);
	}
}
