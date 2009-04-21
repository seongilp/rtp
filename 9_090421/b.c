#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main(void)
{
	char cfk, cfl;
	int fd[2];
	fd_set fdset;
	int n;
	while(1) {
		FD_ZERO(&fdset);
		FD_SET(fd[0], &fdset);
		FD_SET(fd[1], &fdset);
		n = select(fd[1]+1, &fdset, NULL, NULL, NULL);
		if(n>0) {
			if(FD_ISSET(fd[0], &fdset)) {
				read(fd[0], &cfk, 1);
				write(fd[1], &cfk, 1);
			}
			if(FD_ISSET(fd[1], &fdset)) {
				read(fd[1], &cfl, 1);
				write(fd[2], &cfl, 1);
			}
		}
	}
}
