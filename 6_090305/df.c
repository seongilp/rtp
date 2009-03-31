#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
	pid_t pid;
	char buf[20];
	printf("Enter input (n = next, other input terminates) : ");
	fgets(buf, 20, stdin);
	while(buf[0] == 'n') {
		pid = fork();
		if(pid < 0) {
			perror("Fork:");
			exit(1);
		}
		if(pid == 0) {
			sleep(1);
			exit(0);
		}
		printf("Enter input (n=next, other input terminates) : ");
		fgets(buf,20,stdin);
	}
}
