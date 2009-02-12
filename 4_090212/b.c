#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	mode_t new_mode;
	char *ftype;
	int perm;
	stat(argv[1],&buf);
	if(S_ISDIR(buf.st_mode))
		ftype = "Directory";
	else if (S_ISREG(buf.st_mode))
		ftype = "Regular file";
	else if (S_ISCHR(buf.st_mode))
		ftype = "Character device";
	else if (S_ISBLK(buf.st_mode))
		ftype = "Block device";
	else if (S_ISFIFO(buf.st_mode))
		ftype = "FIFO";
	else if (S_ISLNK(buf.st_mode))
		ftype = "Link file";
	else if (S_ISSOCK(buf.st_mode))
		ftype = "Socket..";
	else
		ftype = "Unknown type file";
	ifbuf.st_mode & I_IRUSR;
				
	printf("This file's type is %s\n",ftype);
	printf("File permission is %o\n",perm);
	return 0;
}
