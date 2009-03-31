#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int access_mode, file_flags;
	char *acc_flag,*nb_flag,*fd_flag,*ap_flag;
	int fd;
	fd = open("sample.c",O_RDONLY | O_NONBLOCK);
	file_flags = fcntl(fd, F_GETFL, 0);
	access_mode = file_flags & O_ACCMODE;
	if(access_mode == O_WRONLY)
		acc_flag = "Write Only";
	else if(access_mode == O_RDONLY)
		acc_flag = "Read Only";
	else if(access_mode == O_RDWR)
		acc_flag = "Read / Write";
	if(file_flags & O_NONBLOCK)
		nb_flag = "ON";
	else
		nb_flag = "OFF";
	if(file_flags & FD_CLOEXEC)
		fd_flag = "ON";
	else
		fd_flag = "OFF";
	if(file_flags & O_APPEND)
		ap_flag = "ON";
	else
		ap_flag = "OFF";
	printf("FD_CLOEXEC: %s\n",fd_flag);
	printf("O_NONBLOCK: %s\n",nb_flag);
	printf("O_APPEND: %s\n",ap_flag);
	printf("Access mode: %s\n",acc_flag);
	return 0;
}
