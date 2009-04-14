#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>

void sig_usr(int sig_no);

int main(void)
{
	int pid;
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	pid = fork();
	if(pid > 0) { // parent
		while(1) {
			printf("1");
			fflush(stdout);
			kill(pid,SIGUSR1);
			pause();
		}
	}
	if(pid == 0) { // child
		while(1) {
			pause();
			printf("2");
			fflush(stdout);
			kill(getppid(),SIGUSR2);
		}
	}
	return 0;
}

void sig_usr(int sig_no)
{
	/*
	if(sig_no == SIGUSR1)
		printf("SIGUSR1\n");
	else if(sig_no == SIGUSR2)
		printf("SIGUSR2\n");
		*/
	return;
}
