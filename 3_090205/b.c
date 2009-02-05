#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/errno.h>

int main(void)
{
	int i, fd;
	char buff[5] = "BBBB";
	if( (fd = open("./exlog", O_WRONLY | O_APPEND)) < 0 ) {
		perror("File doesn't exist...");
		return -1;
	}
	else {
		for(i=0;i<=100000;i++) {
	//		lseek(fd, 0L, SEEK_END);
			write(fd, buff, 4);
		}
	}
	close(fd);
	return 0;
}

