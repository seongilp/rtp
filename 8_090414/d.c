#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>

void sig_handler(int sig_no);

int child_running = 1;

int main(void) 
{
	int fd, pid;
	char buf[5] = "";
	signal(SIGCHLD,sig_handler);
	if( (fd = open("./test.log",O_CREAT|O_RDWR|O_APPEND)) < 0 ) {
		perror("File doesn't exist...");
		return -1;
	}
	pid = fork();
	if(pid == 0) { // child
		sprintf(buf,"%d",fd);
		execl("./b","b",buf,NULL);
		perror("exec error");
		exit(0);
	}
	if(pid > 0) {  // parent
		while(child_running) {
			printf("Parent is working...\n");
			sleep(1);
		}
		printf("Child terminated.\n");
	}
	return 0;
}

void sig_handler(int sig_no)
{
	child_running = 0;
	return;
}
