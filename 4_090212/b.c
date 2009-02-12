#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2) {
		perror("Usage: b FILENAME");
		return 1;
	}
	struct stat buf;
	mode_t new_mode;
	char *ftype;
	int perm = 0;
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

	if(buf.st_mode & S_IRUSR)
		perm += 400;
	if(buf.st_mode & S_IWUSR)
		perm += 200;
	if(buf.st_mode & S_IXUSR)
		perm += 100;
	if(buf.st_mode & S_IRGRP)
		perm += 40;
	if(buf.st_mode & S_IWGRP)
		perm += 20;
	if(buf.st_mode & S_IXGRP)
		perm += 10;
	if(buf.st_mode & S_IROTH)
		perm += 4;
	if(buf.st_mode & S_IWOTH)
		perm += 2;
	if(buf.st_mode & S_IXOTH)
		perm += 1;
				
	printf("This file's type is %s\n",ftype);
	printf("File permission is %d\n",perm);
	return 0;
}
