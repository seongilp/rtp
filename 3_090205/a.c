#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/errno.h>

int main(void)
{
	int i, fd;
	char buff[5] = "AAAA";
	if( (fd=open("./exlog", O_WRONLY | O_CREAT | O_APPEND)) < 0) { // O_APPEND is for atomic operation
		if(errno == EEXIST) {
			perror("exist!");
			return -1;
		}
	}
	else {
		for(i=0;i<100000;i++) {
	//		lseek(fd, 0L, SEEK_END);  // this is for Concurrent writing
			write(fd, buff, 4);
		}
	}
	close(fd);
	return 0;
}

