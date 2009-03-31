#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void sig_handler(int sig_no);


int main(void) 
{
	pid = fork();
	if(pid == 0) { // child

	}
	if(pid > 0) {  // parent
		printf("Parent is working...\n");
		pause(1);
		wait(NULL);
		printf("Child terminated.\n");
	}
}

void sig_handler(int sig_no)
{
	
}
