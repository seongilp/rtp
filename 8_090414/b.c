#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <fcntl.h>

int main(int argc, char *argv[]) 
{
	int fd;
	int i;
	char buf[2] = "2";
	sscanf(argv[1],"%d",&fd);
	for(i=0;i<5;i++) {
		write(fd,"2",2);
		sleep(1);
	}
	return 0;
}
