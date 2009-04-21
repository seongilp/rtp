#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

int main(void)
{
	char cfk, cfp;
	fd_set fdset;
	pid_t pid;
	int fd_arr[2], i, j, n;
	j = 0;
	pipe(fd_arr);
	pid = fork();
	if(pid == 0) {
		close(fd_arr[0]);
		for(i=0;i<10;i++) {
			j = j + 1;
			write(fd_arr[1], &j, 1);
			sleep(1);
		}	
		close(fd_arr[1]);
		exit(0);
	}
	close(fd_arr[1]);
	while(1) {
		for(i=0;i<10;i++) {
			if(read(fd_arr[0], &j, 1) == 0) {
				printf("No more input\n");
				return 0;
			}
			printf("%d\n",j);
		}
	}
	close(fd_arr[0]);
}
