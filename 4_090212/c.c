#include <stdio.h>

int main(void)
{
	FILE *file;
	char c[5];
	file = fopen("data.txt","rw");
	while(1)
	{
		fread(&c,1,1,file)
	}
	fflush();
	return 0;
	// exit(0); // second 
	// return 0; // without fflush


}
